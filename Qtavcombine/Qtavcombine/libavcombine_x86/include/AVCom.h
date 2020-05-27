#pragma once
#include "avc_def.h"
#include "IAVCom.h"
class DLL_API AVCom:IAVCom
{
public:
    AVCom();
    ~AVCom();
    void setAudio(LPCSTR audio);
    void setVideo(LPCSTR video);
    void setOutPath(LPCSTR path);
    virtual bool OpenStream();
    virtual bool WriteFile();
private:
    void init();
    void dispose();
private:
    LPCSTR m_audio;
    LPCSTR m_video;
    LPCSTR m_path;
    AVFormatContext* m_pAudioFormatContext;
    AVFormatContext* m_pVideoFormatContext;
    AVFormatContext* m_pOutFormatContext;
    AVCodecParameters* m_pAudioCodecParameters;
    AVCodecParameters* m_pVideoCodecParameters;
    int audio_stream_index;
    int video_stream_index;
    AVStream* m_pOutAudioStream;
    AVStream* m_pOutVideoStream;
};

