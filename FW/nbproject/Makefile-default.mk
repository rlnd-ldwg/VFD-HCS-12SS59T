#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=mkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/FW.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/FW.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=
else
COMPARISON_BUILD=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=/Users/roland/Projects/VFD-HCS-12SS59T/FW/src/main.c /Users/roland/Projects/VFD-HCS-12SS59T/FW/src/spi.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/1799924136/main.o ${OBJECTDIR}/_ext/1799924136/spi.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/1799924136/main.o.d ${OBJECTDIR}/_ext/1799924136/spi.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/1799924136/main.o ${OBJECTDIR}/_ext/1799924136/spi.o

# Source Files
SOURCEFILES=/Users/roland/Projects/VFD-HCS-12SS59T/FW/src/main.c /Users/roland/Projects/VFD-HCS-12SS59T/FW/src/spi.c

# Pack Options 
PACK_COMPILER_OPTIONS=-I "${DFP_DIR}/include"
PACK_COMMON_OPTIONS=-B "${DFP_DIR}/gcc/dev/atmega328p"



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/FW.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=ATmega328P
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/1799924136/main.o: /Users/roland/Projects/VFD-HCS-12SS59T/FW/src/main.c  .generated_files/flags/default/321f23784685e879de91585972e773494cb60ce6 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1799924136" 
	@${RM} ${OBJECTDIR}/_ext/1799924136/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1799924136/main.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328p ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/_ext/1799924136/main.o.d" -MT "${OBJECTDIR}/_ext/1799924136/main.o.d" -MT ${OBJECTDIR}/_ext/1799924136/main.o  -o ${OBJECTDIR}/_ext/1799924136/main.o /Users/roland/Projects/VFD-HCS-12SS59T/FW/src/main.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1799924136/spi.o: /Users/roland/Projects/VFD-HCS-12SS59T/FW/src/spi.c  .generated_files/flags/default/a8ec5934baf79d95a66717c4395aee50aa8d6c83 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1799924136" 
	@${RM} ${OBJECTDIR}/_ext/1799924136/spi.o.d 
	@${RM} ${OBJECTDIR}/_ext/1799924136/spi.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328p ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/_ext/1799924136/spi.o.d" -MT "${OBJECTDIR}/_ext/1799924136/spi.o.d" -MT ${OBJECTDIR}/_ext/1799924136/spi.o  -o ${OBJECTDIR}/_ext/1799924136/spi.o /Users/roland/Projects/VFD-HCS-12SS59T/FW/src/spi.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
else
${OBJECTDIR}/_ext/1799924136/main.o: /Users/roland/Projects/VFD-HCS-12SS59T/FW/src/main.c  .generated_files/flags/default/9272cdbdc0d7beb759c1aaf371b590eaed6d7926 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1799924136" 
	@${RM} ${OBJECTDIR}/_ext/1799924136/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1799924136/main.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328p ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/_ext/1799924136/main.o.d" -MT "${OBJECTDIR}/_ext/1799924136/main.o.d" -MT ${OBJECTDIR}/_ext/1799924136/main.o  -o ${OBJECTDIR}/_ext/1799924136/main.o /Users/roland/Projects/VFD-HCS-12SS59T/FW/src/main.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1799924136/spi.o: /Users/roland/Projects/VFD-HCS-12SS59T/FW/src/spi.c  .generated_files/flags/default/b1fdc7a839b3e58dd804f068fb7a527852631ac6 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1799924136" 
	@${RM} ${OBJECTDIR}/_ext/1799924136/spi.o.d 
	@${RM} ${OBJECTDIR}/_ext/1799924136/spi.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328p ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/_ext/1799924136/spi.o.d" -MT "${OBJECTDIR}/_ext/1799924136/spi.o.d" -MT ${OBJECTDIR}/_ext/1799924136/spi.o  -o ${OBJECTDIR}/_ext/1799924136/spi.o /Users/roland/Projects/VFD-HCS-12SS59T/FW/src/spi.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/FW.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mmcu=atmega328p ${PACK_COMMON_OPTIONS}  -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2 -D__$(MP_PROCESSOR_OPTION)__  -Wl,-Map="${DISTDIR}/FW.${IMAGE_TYPE}.map"    -o ${DISTDIR}/FW.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}      -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_SIMULATOR=1 -Wl,--gc-sections -Wl,--start-group  -Wl,-lm -Wl,--end-group 
	
	
	
	
	
	
else
${DISTDIR}/FW.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mmcu=atmega328p ${PACK_COMMON_OPTIONS}  -D__$(MP_PROCESSOR_OPTION)__  -Wl,-Map="${DISTDIR}/FW.${IMAGE_TYPE}.map"    -o ${DISTDIR}/FW.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}      -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION) -Wl,--gc-sections -Wl,--start-group  -Wl,-lm -Wl,--end-group 
	${MP_CC_DIR}/avr-objcopy -O ihex "${DISTDIR}/FW.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}" "${DISTDIR}/FW.${IMAGE_TYPE}.hex"
	
	
	
	
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${OBJECTDIR}
	${RM} -r ${DISTDIR}

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(wildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
