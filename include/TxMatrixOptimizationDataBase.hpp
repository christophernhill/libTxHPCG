#ifndef TX_MATRIX_OPTIMIZATION_DATA_BASE_HPP
#define TX_MATRIX_OPTIMIZATION_DATA_BASE_HPP

#include <SparseMatrix.hpp>
#include <Vector.hpp>

/**
 * @brief Interface for Tech-X matrix optimization data.
 *
 * @sa SparseMatrix, Vector, TxVectorOptimizationData,
 * TxMatrixOptimizationDataCU, TxMatrixOptimizationDataOCL
 * */
class TxMatrixOptimizationDataBase {
 public:
   TxMatrixOptimizationDataBase() {}
   virtual int ingestLocalMatrix(SparseMatrix& A) = 0;
   virtual int ComputeSPMV(const SparseMatrix& A, Vector& x, Vector& y,
       bool copyIn = true, bool copyOut = true) = 0;
   virtual int ComputeSYMGS(const SparseMatrix& A, const Vector& x, Vector& y,
       int numberOfSmootherSteps = 1, bool copyIn = true,
       bool copyOut = true) = 0;
   virtual int ComputeProlongation(const SparseMatrix& Af, Vector& xf,
       bool copyIn, bool copyOut) = 0;
   virtual int ComputeRestriction(const SparseMatrix& Af, const Vector& rf,
       bool copyIn, bool copyOut) = 0;
   virtual ~TxMatrixOptimizationDataBase() {}

 private:
// Disallow copying to prevent slicing
   TxMatrixOptimizationDataBase(const TxMatrixOptimizationDataBase&);
   TxMatrixOptimizationDataBase& operator=(const TxMatrixOptimizationDataBase&);
};

#endif

