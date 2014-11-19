#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=Cygwin_4.x-Windows
CND_DLIB_EXT=dll
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/870914629/ParkedCar.o \
	${OBJECTDIR}/_ext/870914629/ParkingMeter.o \
	${OBJECTDIR}/_ext/870914629/ParkingTicket.o \
	${OBJECTDIR}/_ext/870914629/PoliceOfficer.o \
	${OBJECTDIR}/_ext/870914629/main.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/gaddis7thedchp14prob14.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/gaddis7thedchp14prob14.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/gaddis7thedchp14prob14 ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/_ext/870914629/ParkedCar.o: ../../source/ParkedCar.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/870914629
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/870914629/ParkedCar.o ../../source/ParkedCar.cpp

${OBJECTDIR}/_ext/870914629/ParkingMeter.o: ../../source/ParkingMeter.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/870914629
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/870914629/ParkingMeter.o ../../source/ParkingMeter.cpp

${OBJECTDIR}/_ext/870914629/ParkingTicket.o: ../../source/ParkingTicket.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/870914629
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/870914629/ParkingTicket.o ../../source/ParkingTicket.cpp

${OBJECTDIR}/_ext/870914629/PoliceOfficer.o: ../../source/PoliceOfficer.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/870914629
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/870914629/PoliceOfficer.o ../../source/PoliceOfficer.cpp

${OBJECTDIR}/_ext/870914629/main.o: ../../source/main.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/870914629
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/870914629/main.o ../../source/main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/gaddis7thedchp14prob14.exe

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
