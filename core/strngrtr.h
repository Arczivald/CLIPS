   /*******************************************************/
   /*      "C" Language Integrated Production System      */
   /*                                                     */
   /*             CLIPS Version 6.20  01/31/02            */
   /*                                                     */
   /*            STRING I/O ROUTER HEADER FILE            */
   /*******************************************************/

/*************************************************************/
/* Purpose: I/O Router routines which allow strings to be    */
/*   used as input and output sources.                       */
/*                                                           */
/* Principal Programmer(s):                                  */
/*      Gary D. Riley                                        */
/*                                                           */
/* Contributing Programmer(s):                               */
/*                                                           */
/* Revision History:                                         */
/*                                                           */
/*************************************************************/

#ifndef _H_strngrtr
#define _H_strngrtr

#ifndef _STDIO_INCLUDED_
#define _STDIO_INCLUDED_
#include <stdio.h>
#endif

#define STRING_ROUTER_DATA 48

struct stringRouter
  {
   char *name;
   char *str;
   size_t currentPosition;
   size_t maximumPosition;
   int readWriteType;
   struct stringRouter *next;
  };

struct stringRouterData
  { 
   struct stringRouter *ListOfStringRouters;
  };

#define StringRouterData(theEnv,execStatus) ((struct stringRouterData *) GetEnvironmentData(theEnv,execStatus,STRING_ROUTER_DATA))

#ifdef LOCALE
#undef LOCALE
#endif

#ifdef _STRNGRTR_SOURCE_
#define LOCALE
#else
#define LOCALE extern
#endif

/**************************/
/* I/O ROUTER DEFINITIONS */
/**************************/

   LOCALE void                           InitializeStringRouter(void *,EXEC_STATUS);
   LOCALE int                            OpenStringSource(void *,EXEC_STATUS,char *,char *,size_t);
   LOCALE int                            OpenTextSource(void *,EXEC_STATUS,char *,char *,size_t,size_t);
   LOCALE int                            CloseStringSource(void *,EXEC_STATUS,char *);
   LOCALE int                            OpenStringDestination(void *,EXEC_STATUS,char *,char *,size_t);
   LOCALE int                            CloseStringDestination(void *,EXEC_STATUS,char *);

#endif


