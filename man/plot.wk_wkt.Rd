% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/plot.R
\name{plot.wk_wkt}
\alias{plot.wk_wkt}
\alias{plot.wk_wkb}
\alias{plot.wk_xy}
\alias{plot.wk_rct}
\alias{plot.wk_crc}
\title{Plot well-known geometry vectors}
\usage{
\method{plot}{wk_wkt}(
  x,
  ...,
  asp = 1,
  bbox = NULL,
  xlab = "",
  ylab = "",
  rule = "evenodd",
  add = FALSE
)

\method{plot}{wk_wkb}(
  x,
  ...,
  asp = 1,
  bbox = NULL,
  xlab = "",
  ylab = "",
  rule = "evenodd",
  add = FALSE
)

\method{plot}{wk_xy}(x, ..., asp = 1, bbox = NULL, xlab = "", ylab = "", add = FALSE)

\method{plot}{wk_rct}(x, ..., asp = 1, bbox = NULL, xlab = "", ylab = "", add = FALSE)

\method{plot}{wk_crc}(x, ..., asp = 1, bbox = NULL, xlab = "", ylab = "", add = FALSE)
}
\arguments{
\item{x}{A \code{\link[=wkt]{wkt()}} or \code{\link[=wkb]{wkb()}} vector.}

\item{...}{Passed to plotting functions for features: \code{\link[graphics:points]{graphics::points()}}
for point and multipoint geometries, \code{\link[graphics:lines]{graphics::lines()}} for linestring
and multilinestring geometries, and \code{\link[graphics:polypath]{graphics::polypath()}} for polygon
and multipolygon geometries.}

\item{asp}{Passed to \code{\link[graphics:plot.default]{graphics::plot()}}}

\item{bbox}{The limits of the plot in the form returned by \code{\link[wkutils:wkb_ranges]{wkt_ranges()}}.}

\item{xlab}{Passed to \code{\link[graphics:plot.default]{graphics::plot()}}}

\item{ylab}{Passed to \code{\link[graphics:plot.default]{graphics::plot()}}}

\item{rule}{The rule to use for filling polygons (see \code{\link[graphics:polypath]{graphics::polypath()}})}

\item{add}{Should a new plot be created, or should \code{x} be added to the
existing plot?}
}
\value{
The input, invisibly.
}
\description{
Plot well-known geometry vectors
}
\examples{
# requires the wkutils package
if (requireNamespace("wkutils")) {
  plot(as_wkt("LINESTRING (0 0, 1 1)"))
  plot(as_wkb("LINESTRING (0 0, 1 1)"))
}

}
