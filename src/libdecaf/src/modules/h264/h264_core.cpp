#include "h264.h"
#include "h264_core.h"

namespace h264
{

int32_t
H264DECMemoryRequirement(int32_t profile, int32_t level, int32_t maxWidth, int32_t maxHeight, int32_t *outSize)
{
   *outSize = maxWidth * maxHeight * 16;
   return 0;
}

int32_t
H264DECCheckMemSegmentation(void *workMem, uint32_t size)
{
   return 0;
}

int32_t
H264DECInitParam(int32_t size, void *workMem)
{
   return 0;
}

int32_t
H264DECSetParam(void *workMem, int32_t id, void *value)
{
   gLog->info("H264DECSetParam {}", id);
   return 0;
}

int32_t
H264DECOpen(void *workMem)
{
   return 0;
}

int32_t
H264DECClose(void *workMem)
{
   return 0;
}

int32_t
H264DECBegin(void *workMem)
{
   return 0;
}

int32_t
H264DECEnd(void *workMem)
{
   return 0;
}

int32_t
H264DECFindDecstartpoint(void *buffer, int32_t size, int32_t *outStartPoint)
{
   *outStartPoint = 256;
   return 0;
}

int32_t
H264DECGetImageSize(void *buffer, int32_t size, int32_t offset, int32_t *outWidth, int32_t *outHeight)
{
   *outWidth = 1024;
   *outHeight = 768;
   return 0;
}

int32_t
H264DECSetBitstream(void *workMem, void *buffer, int32_t size, double timeStamp)
{
   return 0;
}

int32_t
H264DECExecute(void *workMem, void *frameData)
{
   return 0X000000E4;
}

void
Module::registerCoreFunctions()
{
   RegisterKernelFunction(H264DECMemoryRequirement);
   RegisterKernelFunction(H264DECCheckMemSegmentation);
   RegisterKernelFunction(H264DECInitParam);
   RegisterKernelFunction(H264DECSetParam);
   RegisterKernelFunction(H264DECOpen);
   RegisterKernelFunction(H264DECClose);
   RegisterKernelFunction(H264DECBegin);
   RegisterKernelFunction(H264DECEnd);
   RegisterKernelFunction(H264DECFindDecstartpoint);
   RegisterKernelFunction(H264DECGetImageSize);
   RegisterKernelFunction(H264DECSetBitstream);
   RegisterKernelFunction(H264DECExecute);
}

} // namespace h264
