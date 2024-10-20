#include "framework.h"
#include "acme/operating_system.h"


i32 _c_lock_is_active(const char * lpszName)
{

   HANDLE h;

   if(_c_lock(lpszName, &h))
   {
      _c_unlock(&h);
      return false;
   }

   return true;

}


i32 _c_lock(const char * lpszName, void ** pdata)
{

   HANDLE hmutex = ::CreateMutexW(nullptr, false, L"Global\\::ca::account::ca2_spa::7807e510-5579-11dd-ae16-0800200c7784");

   DWORD dwLastError = ::GetLastError();

   if(dwLastError == ERROR_ALREADY_EXISTS)
   {
      ::CloseHandle(hmutex);
      return 0;
   }
   if(hmutex == INVALID_HANDLE_VALUE)
      return 0;

   HANDLE * phandle = ___new HANDLE;
   *phandle = hmutex;
   *pdata = phandle;

   return 1;

}


i32 _c_unlock(void ** pdata)
{

   HANDLE * phandle = (HANDLE *) *pdata;

   ::CloseHandle(*phandle);

   *phandle = nullptr;

   delete phandle;

   *pdata = nullptr;

   return 1;

}
