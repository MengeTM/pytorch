#include <onnx/onnx_pb.h>
#include <torch/csrc/onnx/init.h>
#include <torch/csrc/onnx/onnx.h>
#include <torch/version.h>

namespace torch {
namespace onnx {
void initONNXBindings(PyObject* module) {
  auto m = py::handle(module).cast<py::module>();
  auto onnx = m.def_submodule("_onnx");
  py::enum_<::ONNX_NAMESPACE::TensorProto_DataType>(onnx, "TensorProtoDataType")
      .value("UNDEFINED", ::ONNX_NAMESPACE::TensorProto_DataType_UNDEFINED)
      .value("FLOAT", ::ONNX_NAMESPACE::TensorProto_DataType_FLOAT)
      .value("UINT8", ::ONNX_NAMESPACE::TensorProto_DataType_UINT8)
      .value("INT8", ::ONNX_NAMESPACE::TensorProto_DataType_INT8)
      .value("UINT16", ::ONNX_NAMESPACE::TensorProto_DataType_UINT16)
      .value("INT16", ::ONNX_NAMESPACE::TensorProto_DataType_INT16)
      .value("INT32", ::ONNX_NAMESPACE::TensorProto_DataType_INT32)
      .value("INT64", ::ONNX_NAMESPACE::TensorProto_DataType_INT64)
      .value("STRING", ::ONNX_NAMESPACE::TensorProto_DataType_STRING)
      .value("BOOL", ::ONNX_NAMESPACE::TensorProto_DataType_BOOL)
      .value("FLOAT16", ::ONNX_NAMESPACE::TensorProto_DataType_FLOAT16)
      .value("DOUBLE", ::ONNX_NAMESPACE::TensorProto_DataType_DOUBLE)
      .value("UINT32", ::ONNX_NAMESPACE::TensorProto_DataType_UINT32)
      .value("UINT64", ::ONNX_NAMESPACE::TensorProto_DataType_UINT64)
      .value("COMPLEX64", ::ONNX_NAMESPACE::TensorProto_DataType_COMPLEX64)
      .value("COMPLEX128", ::ONNX_NAMESPACE::TensorProto_DataType_COMPLEX128)
      .value("BFLOAT16", ::ONNX_NAMESPACE::TensorProto_DataType_BFLOAT16);

  py::enum_<OperatorExportTypes>(onnx, "OperatorExportTypes")
      .value("ONNX", OperatorExportTypes::ONNX)
      .value("ONNX_ATEN", OperatorExportTypes::ONNX_ATEN)
      .value("ONNX_ATEN_FALLBACK", OperatorExportTypes::ONNX_ATEN_FALLBACK)
      .value("ONNX_FALLTHROUGH", OperatorExportTypes::ONNX_FALLTHROUGH);

  py::enum_<TrainingMode>(onnx, "TrainingMode")
      .value("EVAL", TrainingMode::EVAL)
      .value("PRESERVE", TrainingMode::PRESERVE)
      .value("TRAINING", TrainingMode::TRAINING);

  onnx.attr("PRODUCER_VERSION") = py::str(TORCH_VERSION);

#ifdef BUILD_CAFFE2
  onnx.attr("_CAFFE2_ATEN_FALLBACK") = true;
#else
  onnx.attr("_CAFFE2_ATEN_FALLBACK") = false;
#endif
}
} // namespace onnx
} // namespace torch
