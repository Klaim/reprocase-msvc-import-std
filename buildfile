libs =
import libs += libboost-unordered%lib{boost_unordered}

./: exe{simpleapp} doc{README.md} manifest

exe{simpleapp}: {hxx ixx txx cxx mxx}{*} $libs

cxx.poptions =+ "-I$out_root" "-I$src_root"
