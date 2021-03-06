# https://wiki.debian.org/GCC5
# We may see binaries built with gcc5 run or linked into gcc4 environment
# so use the older libstdc++ standard for now until we don't support gcc4
# on the host system.
BUILD_CXXFLAGS_append = " -D_GLIBCXX_USE_CXX11_ABI=0"

# icu configure defaults to CXX11 if no -std= option is passed in CXXFLAGS
# therefore pass one
BUILD_CXXFLAGS_append_pn-icu-native = " -std=c++98"

# Some distros (ubuntu 16.10, debian-testing) default to gcc configured with
# --enable-default-pie (see gcc -v). This breaks e.g. prelink-native on a pie
# default system if binutils-native was built on a system which is not pie default
# We therefore enable pie unconditionally for native recipes where static libs are
# used such as libiberty from binutils, for now, until our minimum distro set is
# all default pie.
BUILD_CFLAGS_append_pn-binutils-native = " -pie -fpie"
