#pragma once

#ifdef KINEMO_WIN_64
	#ifdef KINEMO_CORE
		#define KINEMO_API __declspec(dllexport)
	#else
		#define KINEMO_API __declspec(dllimport)
	#endif
#endif

#define BIT(x) (1 << x)