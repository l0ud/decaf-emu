#pragma once
#include "common/types.h"
#include "common/be_val.h"

namespace h264
{

int32_t
H264DECMemoryRequirement(int32_t profile, int32_t level, int32_t maxWidth, int32_t maxHeight, int32_t *outSize);

int32_t
H264DECCheckMemSegmentation(void *workMem, uint32_t size);

int32_t
H264DECInitParam(int32_t size, void *workMem);

int32_t
H264DECOpen(void *workMem);

int32_t
H264DECClose(void *workMem);

int32_t
H264DECBegin(void *workMem);

int32_t
H264DECEnd(void *workMem);

int32_t
H264DECFindDecstartpoint(void *buffer, int32_t size, int32_t *outStartPoint);

int32_t
H264DECGetImageSize(void *buffer, int32_t size, int32_t offset, int32_t *outWidth, int32_t *outHeight);

int32_t
H264DECSetBitstream(void *workMem, void *buffer, int32_t size, double timeStamp);

int32_t
H264DECExecute(void *workMem, void *frameData);

} // namespace h264
