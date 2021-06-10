aux_source_directory(./src/utils SRCS)
add_library(OQSDK_Utils ${SRCS})

aux_source_directory(./src/core SRCS)
add_library(OQSDK_Core ${SRCS})