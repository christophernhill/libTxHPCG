include_directories(${CMAKE_CURRENT_SOURCE_DIR})
set(CUTxHPCG_SOURCES
    CPCSR.cpp
    ComputeDotProduct.cpp
    ExchangeHalo.cpp
    TxMatrixOptimizationDataCU.cpp
    TxVectorOptimizationDataCU.cpp
    )
set(CUTxHPCG_SOURCES_CU
    Kernels.cu
   )
cuda_add_library(CUTxHPCG
    ${CUTxHPCG_SOURCES}
    ${CUTxHPCG_SOURCES_CU}
    )
target_link_libraries(CUTxHPCG
    TxHPCG
    ${Gelus_LIBRARIES}
    ${Cusparse_LIBRARIES})
install(TARGETS CUTxHPCG DESTINATION lib)

