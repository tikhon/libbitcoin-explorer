# Declare the required version of autoconf.
AC_PREREQ([2.65])

# Process command-line arguments and perform initialization and verification.
AC_INIT([libitcoin-explorer], [2.0.0], [eric@voskuil.org])

# Do compilation tests.
AC_LANG(C++)

# Specify the temporary directory for build tools.
AC_CONFIG_AUX_DIR([build-aux])

# Specify the directory of additional local Autoconf macros.
AC_CONFIG_MACRO_DIR([m4])

# Run macros for operation of generated Makefiles, enable non-recursive make.
AM_INIT_AUTOMAKE([subdir-objects])

# Enable C and Posix extensions that may be disabled on certain platforms.
AC_USE_SYSTEM_EXTENSIONS

# Enable the archiver.
AM_PROG_AR

# Initialize libtool.
LT_INIT

# Determine C++ compiler to use.
AC_PROG_CXX

# Enable shared libraries if available, and static if they don't conflict.
AC_PROG_LIBTOOL

# Declare using the GNU C library (glibc).
AC_GNU_SOURCE

# Compute the canonical host-system type variable host, including host_os.
AC_CANONICAL_HOST

# Check for baseline language coverage in the compiler for the C++11 standard.
AX_CXX_COMPILE_STDCXX_11([noext], [mandatory])

# Enable silent rules option.
m4_ifdef([AM_SILENT_RULES], [AM_SILENT_RULES([yes])])

# Declare environment variables that affect the build.
#------------------------------------------------------------------------------
AC_ARG_VAR([CC], "C compiler to use, such as gcc or clang")
AC_ARG_VAR([CXX], "C++ compiler to use, such as g++ or clang++")
AC_ARG_VAR([PKG_CONFIG_PATH], "Additional directories for package discovery.")

# Support --with-pkgconfigdir option (after verifying package config install)
#------------------------------------------------------------------------------
PKG_PROG_PKG_CONFIG
AC_MSG_CHECKING(--with-pkgconfigdir option)
AC_ARG_WITH([pkgconfigdir], 
    AS_HELP_STRING([--with-pkgconfigdir=PATH], 
        [Path to pkgconfig directory.]),
    [pkgconfigdir=$withval], 
    [pkgconfigdir=${libdir}/pkgconfig])
AC_MSG_RESULT($pkgconfigdir)
AC_SUBST([pkgconfigdir])

# Support --enable-debug option
#------------------------------------------------------------------------------
AC_MSG_CHECKING(--enable-debug option)
AC_ARG_ENABLE([debug],
    AS_HELP_STRING([--enable-debug], 
        [Compile with debug assertions.]),
    [enable_debug=$enableval],
    [enable_debug=no])
AC_MSG_RESULT($enable_debug)
AS_IF([test x$enable_debug != xno], AC_DEFINE([DEBUG]))

# Support --enable-testnet option
#------------------------------------------------------------------------------
AC_MSG_CHECKING(--enable-testnet option)
AC_ARG_ENABLE([testnet],
    AS_HELP_STRING([--enable-testnet], 
        [Compile for testnet.]),
    [enable_testnet=$enableval],
    [enable_testnet=no])
AC_MSG_RESULT($enable_testnet)
AS_IF([test x$enable_testnet != xno], AC_DEFINE([ENABLE_TESTNET]))

# Support --with-tests option
#------------------------------------------------------------------------------
AC_MSG_CHECKING(--with-tests option)
AC_ARG_WITH([tests],
    AS_HELP_STRING([--with-tests], 
        [Compile with unit tests.]),
    [with_tests=$withval],
    [with_tests=yes])
AC_MSG_RESULT($with_tests)

# Require boost min version.
#------------------------------------------------------------------------------
# Boost does not publish package configs but has m4 tests.
# The BOOST_ROOT environment variable is *not* prioritize by the m4 tests.
# As a result there may be dependency conflicts between installed versions
# and a version specified in BOOST_ROOT.
# These scripts may produce incorrect error message text.
AX_BOOST_BASE([1.49],,
    [AC_MSG_ERROR([Boost 1.49 or later is required but was not found.])])
AX_BOOST_CHRONO
AX_BOOST_DATE_TIME
AX_BOOST_FILESYSTEM
AX_BOOST_PROGRAM_OPTIONS
AX_BOOST_REGEX
AX_BOOST_SYSTEM

# Require GMP.
#------------------------------------------------------------------------------
# GMP does not publish a package config.
AC_CHECK_HEADER([gmp.h],
    [],
    [AC_MSG_ERROR([GMP header is required but was not found.])],-)
AC_CHECK_LIB([gmp],[__gmpz_init],
    [AC_SUBST([gmp_LIBS], [-lgmp])],
    [AC_MSG_ERROR([GMP library is required but was not found.])])

# Require bitcoin, bitcoin_client and sodium package min versions.
#------------------------------------------------------------------------------
PKG_CHECK_MODULES([bitcoin_client], [libbitcoin-client >= 2.0.0])
PKG_CHECK_MODULES([sodium], [libsodium >= 1.0.0])

# Require test dependencies if $with_tests is set.
#------------------------------------------------------------------------------
AS_IF([test x$with_tests != xno], [AX_BOOST_UNIT_TEST_FRAMEWORK])
AM_CONDITIONAL([WITH_TESTS], [test x$with_tests != xno])
AM_COND_IF([WITH_TESTS], [AC_MSG_NOTICE([WITH_TESTS defined])])
AM_CONDITIONAL([SET_BOOST_TEST_DYN_LINK], [test x$enable_shared != xno])
AM_COND_IF([SET_BOOST_TEST_DYN_LINK],
    [AC_MSG_NOTICE([BOOST_TEST_DYN_LINK defined])])

# Set warning levels.
#------------------------------------------------------------------------------
AX_CHECK_COMPILE_FLAG([-Wall],
    [CXXFLAGS="$CXXFLAGS -Wall"])

AX_CHECK_COMPILE_FLAG([-Wextra],
    [CXXFLAGS="$CXXFLAGS -Wextra"])

AX_CHECK_COMPILE_FLAG([-Wno-missing-braces],
    [CXXFLAGS="$CXXFLAGS -Wno-missing-braces"])

AX_CHECK_COMPILE_FLAG([-Wno-unused-function],
    [CXXFLAGS="$CXXFLAGS -Wno-unused-function"])

# This cleans up for boost headers.
AX_CHECK_COMPILE_FLAG([-Wno-unused-local-typedefs],
    [CXXFLAGS="$CXXFLAGS -Wno-unused-local-typedefs"])

# This cleans up for a boost property_tree headers (with boost exceptions off).
# -Wpedantic causes lots of boost 1.49 included header warnings, so leave off.
#AX_CHECK_COMPILE_FLAG([-Wpedantic],
#    [CXXFLAGS="$CXXFLAGS -Wpedantic"],
#    AX_CHECK_COMPILE_FLAG([-pedantic],
#        [CXXFLAGS="$CXXFLAGS -pedantic"]))
AX_CHECK_COMPILE_FLAG([-Wno-maybe-uninitialized],
    [CXXFLAGS="$CXXFLAGS -Wno-maybe-uninitialized"])
AX_CHECK_COMPILE_FLAG([-Wno-return-type],
    [CXXFLAGS="$CXXFLAGS -Wno-return-type"])

# Prevent clang from warning about unknown warnings (even though checked),
# specifically -Wno-maybe-uninitialized and -Wno-unused-local-typedefs.
AX_CHECK_COMPILE_FLAG([-Wno-unknown-warning-option],
    [CXXFLAGS="$CXXFLAGS -Wno-unknown-warning-option"])

# This cleans up for protobuf headers.
AX_CHECK_COMPILE_FLAG([-Wno-sign-compare],
    [CXXFLAGS="$CXXFLAGS -Wno-sign-compare"])
AX_CHECK_COMPILE_FLAG([-Wno-nested-anon-types],
    [CXXFLAGS="$CXXFLAGS -Wno-nested-anon-types"])
AX_CHECK_COMPILE_FLAG([-Wno-unused-parameter],
    [CXXFLAGS="$CXXFLAGS -Wno-unused-parameter"])

# Set compiler flags.
#------------------------------------------------------------------------------
#AX_CHECK_COMPILE_FLAG([-fvisibility-inlines-hidden],
#    [CXXFLAGS="$CXXFLAGS -fvisibility-inlines-hidden"])

#AX_CHECK_COMPILE_FLAG([-fvisibility=internal],
#    [CXXFLAGS="$CXXFLAGS -fvisibility=internal"],
#    AX_CHECK_COMPILE_FLAG([-fvisibility=hidden],
#        [CXXFLAGS="$CXXFLAGS -fvisibility=hidden"]))

AX_CHECK_COMPILE_FLAG([-fstack-protector],
    [AX_CHECK_LINK_FLAG([-fstack-protector],
        [CXXFLAGS="$CXXFLAGS -fstack-protector"])])

AX_CHECK_COMPILE_FLAG([-fstack-protector-all],
    [AX_CHECK_LINK_FLAG([-fstack-protector-all],
        [CXXFLAGS="$CXXFLAGS -fstack-protector-all"])])

# Set unconditional preprocessor defines.
#------------------------------------------------------------------------------ 
AC_DEFINE(BOOST_NO_EXCEPTIONS)
AC_DEFINE(BOOST_EXCEPTION_DISABLE)

# Generate output files.
#------------------------------------------------------------------------------
AC_CONFIG_FILES([Makefile libbitcoin-explorer.pc])
AC_OUTPUT
