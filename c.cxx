#include <espeak/speak_lib.h>
#include <tesseract/baseapi.h>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
int SynthCallback(short *wav, int numsamples, espeak_EVENT *events)
	{
		return 0;
	}
void Say( const char* Text )
	{
		espeak_Initialize(AUDIO_OUTPUT_SYNCH_PLAYBACK,0,NULL,espeakINITIALIZE_PHONEME_EVENTS); 
		espeak_SetSynthCallback(SynthCallback);
		espeak_Synth(Text, 0, 0, POS_SENTENCE, 0, espeakCHARS_AUTO, NULL, NULL);
		espeak_Terminate();
	}
char* GetText(cv::Mat img)
	{
    		char *outText;
		tesseract::TessBaseAPI *api = new tesseract::TessBaseAPI();
		api->Init(NULL, "eng");
		api->SetImage((uchar*)img.data, img.size().width, img.size().height, img.channels(), (int)img.step1());
		outText = api->GetUTF8Text();
    		api->End();
		return outText;
	}
int main(int argc, const char *argv[])
	{
		Say(GetText(cv::imread(argv[1])));
		return 0;
	}

