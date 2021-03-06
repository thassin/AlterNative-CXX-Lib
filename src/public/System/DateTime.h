#pragma once
#include "System.h"
#include <boost/date_time.hpp>
#include "Exception/SystemException/ArgumentException/ArgumentOutOfRangeException.h"
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/date_time/posix_time/posix_time_io.hpp>
#include "DateTimeKind.h"

#define TIME_T_EPOCH ptime(date(1970,1,1))
#define TICKS_PER_MILLISECOND time_duration::ticks_per_second()/1000
using namespace boost::gregorian;
using namespace boost::posix_time;
namespace System{


	class DateTime : public virtual Object
	{
	private:
		long long DateData;//Ticks
		long long TicksPerMillisecond;
		time_duration time_duration_from_ticks(time_duration::tick_type ticks);		
		void _init();
	public:	
		DateTime();
		~DateTime();
		DateTime(long long ticks);
		DateTime(int year, int month, int day);
		DateTime* AddMilliseconds(int milliseconds);
		static DateTime* getNow();
		static DateTime* getUtcNow();
		String* ToString();
	};
}