#pragma once
#include "avc_def.h"
class DLL_API IAVCom
{

public:
	virtual bool OpenStream() = 0;
	virtual bool WriteFile() = 0;
protected:
	AVFormatContext* OpenMediaInput(LPCSTR fileName);
	AVFormatContext* OpenMediaOutput(LPCSTR fileName);
	void QueryStream(AVFormatContext* pCtx, AVMediaType type, AVCodecParameters** ppCodec, int* pIndex);
	void StreamCopy(AVFormatContext* in_ctx, int in_index, AVFormatContext* out_ctx, int out_index);
	AVStream* AppendStream(AVFormatContext* pCtx);
	void CopyCodec(AVCodecParameters* dst,const AVCodecParameters* src);
	void WriteHeader(AVFormatContext* pCtx, AVDictionary* opts=NULL);
	void WriteTrailer(AVFormatContext* pCtx);
};

