/**
 @file
 Contains debug macro definitions for LiquidMenu library.
 */

#ifndef MRV_DEBUG_H_
#define MRV_DEBUG_H_

	#define _MRVDEBUG_ false


	#if _MRVDEBUG_

		#include <MemoryFree.h>
		static void printMemoryUsage() {

			//Serial.print(F("-"));
			/*
			Serial.print(F("--------------\nfreeMemory()="));
			Serial.println(freeMemory());
			Serial.println(F("--------------"));
			*/
		}

		#include <Arduino.h>
		#define MRVDEBUG(x)             Serial.print(x);delay(100);
		#define MRVDEBUGLN(x)           Serial.println(x);delay(100);
		#define MRVDEBUG_FORMAT(x,y)    Serial.print(x,y);delay(100);
		#define MRVDEBUGLN_FORMAT(x,y)  Serial.println(x,y);delay(100);
		#define MRVDEBUGx2(x,y)         Serial.print(x);Serial.print(y);
		#define MRVDEBUGx2LN(x,y)       Serial.print(x);Serial.println(y);
		#define MRVDEBUGx3(x,y,z)       Serial.print(x);Serial.print(y);Serial.print(z);
		#define MRVDEBUGx3LN(x,y,z)     Serial.print(x);Serial.print(y);Serial.println(z);
		#define MRVDEBUGx4(x,y,z,k)     Serial.print(x);Serial.print(y);Serial.print(z);Serial.print(k);
		#define MRVDEBUGx4LN(x,y,z,k)   Serial.print(x);Serial.print(y);Serial.print(z);Serial.println(k);
		#define MRVDEBUGx5(x,y,z,k,g)   Serial.print(x);Serial.print(y);Serial.print(z);Serial.print(k);Serial.print(g);
		#define MRVDEBUGx5LN(x,y,z,k,g) Serial.print(x);Serial.print(y);Serial.print(z);Serial.print(k);Serial.println(g);

	#else

		static void printMemoryUsage() {
		}

		#define MRVDEBUG(x)				/// Debug print
		#define MRVDEBUGLN(x)				/// Debug print with newline
		#define MRVDEBUG_FORMAT(x,y)		/// Debug print two parameters
		#define MRVDEBUGLN_FORMAT(x,y)	/// Debug print two parameters with newline
		#define MRVDEBUGx2(x,y)			/// Debug print 2 infos em 2 prints
		#define MRVDEBUGx2LN(x,y)			/// Debug print 2 infos em 2 prints com newline
		#define MRVDEBUGx3(x,y,z)			/// Debug print 3 infos em 3 prints
		#define MRVDEBUGx3LN(x,y,z)		/// Debug print 3 infos em 3 prints com newline
		#define MRVDEBUGx4(x,y,z,k)		/// Debug print 4 infos em 4 prints
		#define MRVDEBUGx4LN(x,y,z,k)		/// Debug print 4 infos em 4 prints com newline
		#define MRVDEBUGx5(x,y,z,k,g)		/// Debug print 5 infos em 5 prints
		#define MRVDEBUGx5LN(x,y,z,k,g)	/// Debug print 5 infos em 5 prints com newline
	#endif

#endif
