
#include <R.h>
#include <Rinternals.h>
#include <R_ext/GraphicsEngine.h>

// something like grid::gpar() or par(), but the raw values that are needed
R_GE_gcontext makeContext(
  /*
   * Line characteristics
   */
  rcolor col,            /* pen colour (lines, text, borders, ...) */
  rcolor fill,           /* fill colour (for polygons, circles, rects, ...) */
  double gamma,          /* Gamma correction */
  /*
   * Line characteristics
   */
  double lwd,            /* Line width (roughly number of pixels) */
  int lty,               /* Line type (solid, dashed, dotted, ...) */
  R_GE_lineend lend,     /* Line end */
  R_GE_linejoin ljoin,   /* line join */
  double lmitre,         /* line mitre */
  /*
   * Text characteristics
   */
  double cex,            /* Character expansion (font size = fontsize*cex) */
  double ps,             /* Font size in points */
  double lineheight,     /* Line height (multiply by font size) */
  int fontface,          /* Font face (plain, italic, bold, ...) */
  const char* fontfamily /* Font family */
) {
  R_GE_gcontext context;
  context.col = col;
  context.fill = fill;
  context.gamma = gamma;
  context.lwd = lwd;
  context.lty = lty;
  context.lend = lend;
  context.ljoin = ljoin;
  context.lmitre = lmitre;
  context.cex = cex;
  context.ps = ps;
  context.lineheight = lineheight;
  context.fontface = fontface;
  strcpy(context.fontfamily, fontfamily);

  return context;
}

// defaults, as far as I can tell (devout pkg useful for this!)
R_GE_gcontext makeDefaultContext() {
  return makeContext(
    R_GE_str2col("black"), // col
    R_GE_str2col("white"), // fill
    1, // gamma
    1, // lwd
    0, // lty
    GE_ROUND_CAP, // lend
    GE_ROUND_JOIN, // ljoin
    10, // lmitre
    1, // cex,
    12, // ps
    1, // lineheight
    1, // fontface
    "" // fontfamily
  );
}

// must be called using .External2(), because call, op, and args
// are necessary for the recording (which is necessary for
// interactive devices like RStudioGD)
SEXP C_testPoint(SEXP call, SEXP op, SEXP args, SEXP rho) {
  pGEDevDesc dd = GEcurrentDevice();
  R_GE_gcontext context = makeDefaultContext();

  double left = dd->dev->left;
  double bottom = dd->dev->bottom;
  double right = dd->dev->right;
  double top = dd->dev->top;

  // plot one point in the middle
  double x = 0.5;
  double y = 0.5;

  double gx = left + x * (right - left);
  double gy = top + y * (bottom - top);

  // start drawing
  GEMode(1, dd);

  // remove clip that may have been applied
  // note order (left, bottom, right, top)
  GESetClip(left, bottom, right, top, dd);

  // pch = 1, size = 25px (device coordinates)
  GESymbol(gx, gy, 1, 25, &context, dd);

  // record the graphics operation
  // needed for interactive devices that replay the plot
  // can check if is recording by checking GERecording(call, dd)
  // (call will be R_NilValue)
  GErecordGraphicOperation(op, args, dd);

  // stop drawing
  GEMode(0, dd);

  // return an SEXP or R crashes
  return  R_NilValue;
}
