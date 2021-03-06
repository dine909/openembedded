require gcc-common.inc

BINV = "4.3.2"
PV = "4.3.2+csl-arm-2008q3-39"

FILESDIR = "${FILE_DIRNAME}/gcc-csl-arm-2008q3"

SRC_URI = "http://www.codesourcery.com/public/gnu_toolchain/arm-none-eabi/arm-2008q3-39-arm-none-eabi.src.tar.bz2;name=archive \
           file://gcc-csl-2008q3-hotfix.diff \
           file://arm-nolibfloat.patch \
           file://arm-softfloat.patch \
           file://gcc-4.3.1-ARCH_FLAGS_FOR_TARGET.patch \
           file://gcc-flags-for-build.patch \
           file://gcc-4.3.1-SYSROOT_CFLAGS_FOR_TARGET.patch \
           file://gfortran-4.3.x.patch \
"


S = "${WORKDIR}/gcc-4.3"

do_unpack2() {
	cd ${WORKDIR}
	tar -xvjf ./arm-2008q3-39-arm-none-eabi/gcc-2008q3-39.tar.bz2
}

# Language Overrides
FORTRAN = ""
FORTRAN_linux-gnueabi = ",fortran"
#JAVA = ",java"

EXTRA_OECONF_BASE = "--enable-libssp --disable-bootstrap --disable-libgomp --disable-libmudflap"
ARM_INSTRUCTION_SET = "arm"

addtask unpack2 after do_unpack before do_patch

SRC_URI[archive.md5sum] = "67196fcfe5c95bae1a5bb8a63a1bb74d"
SRC_URI[archive.sha256sum] = "68da29f515a26ca1b5722c940615ddc4b0550b2b1ad5d11129b1da636c353160"
