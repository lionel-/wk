
# .External2 is needed because the 'op' and 'args'
# SEXPs are what need to be passed to GErecordGraphicOperation()
test_point <-  function() {
  .External2(getNativeSymbolInfo("C_testPoint", "wk"))
}

# Needed for Rcpp to pick up on "C_testPoint"
test_point2 <-  function() {
  .Call("C_testPoint")
}
