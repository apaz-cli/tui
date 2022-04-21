typedef long int ptrdiff_t;
typedef long unsigned int size_t;
typedef int wchar_t;
typedef struct {
  long long __clang_max_align_nonce1
      __attribute__((__aligned__(__alignof__(long long))));
  long double __clang_max_align_nonce2
      __attribute__((__aligned__(__alignof__(long double))));
} max_align_t;


typedef float _Float32;
typedef double _Float64;
typedef double _Float32x;
typedef long double _Float64x;






typedef __builtin_va_list va_list;
typedef __builtin_va_list __gnuc_va_list;

typedef unsigned int wint_t;



typedef struct
{
  int __count;
  union
  {
    unsigned int __wch;
    char __wchb[4];
  } __value;
} __mbstate_t;

typedef __mbstate_t mbstate_t;



struct _IO_FILE;
typedef struct _IO_FILE __FILE;





struct _IO_FILE;


typedef struct _IO_FILE FILE;


struct __locale_struct
{

  struct __locale_data *__locales[13];


  const unsigned short int *__ctype_b;
  const int *__ctype_tolower;
  const int *__ctype_toupper;


  const char *__names[13];
};

typedef struct __locale_struct *__locale_t;

typedef __locale_t locale_t;
struct tm;



extern wchar_t *wcscpy (wchar_t *__restrict __dest,
   const wchar_t *__restrict __src)
     __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (1, 2)));


extern wchar_t *wcsncpy (wchar_t *__restrict __dest,
    const wchar_t *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (1, 2)));


extern wchar_t *wcscat (wchar_t *__restrict __dest,
   const wchar_t *__restrict __src)
     __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (1, 2)));

extern wchar_t *wcsncat (wchar_t *__restrict __dest,
    const wchar_t *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (1, 2)));


extern int wcscmp (const wchar_t *__s1, const wchar_t *__s2)
     __attribute__ ((__nothrow__ )) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));

extern int wcsncmp (const wchar_t *__s1, const wchar_t *__s2, size_t __n)
     __attribute__ ((__nothrow__ )) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));



extern int wcscasecmp (const wchar_t *__s1, const wchar_t *__s2) __attribute__ ((__nothrow__ ));


extern int wcsncasecmp (const wchar_t *__s1, const wchar_t *__s2,
   size_t __n) __attribute__ ((__nothrow__ ));



extern int wcscasecmp_l (const wchar_t *__s1, const wchar_t *__s2,
    locale_t __loc) __attribute__ ((__nothrow__ ));

extern int wcsncasecmp_l (const wchar_t *__s1, const wchar_t *__s2,
     size_t __n, locale_t __loc) __attribute__ ((__nothrow__ ));




extern int wcscoll (const wchar_t *__s1, const wchar_t *__s2) __attribute__ ((__nothrow__ ));



extern size_t wcsxfrm (wchar_t *__restrict __s1,
         const wchar_t *__restrict __s2, size_t __n) __attribute__ ((__nothrow__ ));







extern int wcscoll_l (const wchar_t *__s1, const wchar_t *__s2,
        locale_t __loc) __attribute__ ((__nothrow__ ));




extern size_t wcsxfrm_l (wchar_t *__s1, const wchar_t *__s2,
    size_t __n, locale_t __loc) __attribute__ ((__nothrow__ ));


extern wchar_t *wcsdup (const wchar_t *__s) __attribute__ ((__nothrow__ )) __attribute__ ((__malloc__));
extern wchar_t *wcschr (const wchar_t *__wcs, wchar_t __wc)
     __attribute__ ((__nothrow__ )) __attribute__ ((__pure__));
extern wchar_t *wcsrchr (const wchar_t *__wcs, wchar_t __wc)
     __attribute__ ((__nothrow__ )) __attribute__ ((__pure__));
extern size_t wcscspn (const wchar_t *__wcs, const wchar_t *__reject)
     __attribute__ ((__nothrow__ )) __attribute__ ((__pure__));


extern size_t wcsspn (const wchar_t *__wcs, const wchar_t *__accept)
     __attribute__ ((__nothrow__ )) __attribute__ ((__pure__));
extern wchar_t *wcspbrk (const wchar_t *__wcs, const wchar_t *__accept)
     __attribute__ ((__nothrow__ )) __attribute__ ((__pure__));
extern wchar_t *wcsstr (const wchar_t *__haystack, const wchar_t *__needle)
     __attribute__ ((__nothrow__ )) __attribute__ ((__pure__));



extern wchar_t *wcstok (wchar_t *__restrict __s,
   const wchar_t *__restrict __delim,
   wchar_t **__restrict __ptr) __attribute__ ((__nothrow__ ));


extern size_t wcslen (const wchar_t *__s) __attribute__ ((__nothrow__ )) __attribute__ ((__pure__));
extern size_t wcsnlen (const wchar_t *__s, size_t __maxlen)
     __attribute__ ((__nothrow__ )) __attribute__ ((__pure__));
extern wchar_t *wmemchr (const wchar_t *__s, wchar_t __c, size_t __n)
     __attribute__ ((__nothrow__ )) __attribute__ ((__pure__));



extern int wmemcmp (const wchar_t *__s1, const wchar_t *__s2, size_t __n)
     __attribute__ ((__nothrow__ )) __attribute__ ((__pure__));


extern wchar_t *wmemcpy (wchar_t *__restrict __s1,
    const wchar_t *__restrict __s2, size_t __n) __attribute__ ((__nothrow__ ));



extern wchar_t *wmemmove (wchar_t *__s1, const wchar_t *__s2, size_t __n)
     __attribute__ ((__nothrow__ ));


extern wchar_t *wmemset (wchar_t *__s, wchar_t __c, size_t __n) __attribute__ ((__nothrow__ ));
extern wint_t btowc (int __c) __attribute__ ((__nothrow__ ));



extern int wctob (wint_t __c) __attribute__ ((__nothrow__ ));



extern int mbsinit (const mbstate_t *__ps) __attribute__ ((__nothrow__ )) __attribute__ ((__pure__));



extern size_t mbrtowc (wchar_t *__restrict __pwc,
         const char *__restrict __s, size_t __n,
         mbstate_t *__restrict __p) __attribute__ ((__nothrow__ ));


extern size_t wcrtomb (char *__restrict __s, wchar_t __wc,
         mbstate_t *__restrict __ps) __attribute__ ((__nothrow__ ));


extern size_t __mbrlen (const char *__restrict __s, size_t __n,
   mbstate_t *__restrict __ps) __attribute__ ((__nothrow__ ));
extern size_t mbrlen (const char *__restrict __s, size_t __n,
        mbstate_t *__restrict __ps) __attribute__ ((__nothrow__ ));
extern size_t mbsrtowcs (wchar_t *__restrict __dst,
    const char **__restrict __src, size_t __len,
    mbstate_t *__restrict __ps) __attribute__ ((__nothrow__ ));



extern size_t wcsrtombs (char *__restrict __dst,
    const wchar_t **__restrict __src, size_t __len,
    mbstate_t *__restrict __ps) __attribute__ ((__nothrow__ ));





extern size_t mbsnrtowcs (wchar_t *__restrict __dst,
     const char **__restrict __src, size_t __nmc,
     size_t __len, mbstate_t *__restrict __ps) __attribute__ ((__nothrow__ ));



extern size_t wcsnrtombs (char *__restrict __dst,
     const wchar_t **__restrict __src,
     size_t __nwc, size_t __len,
     mbstate_t *__restrict __ps) __attribute__ ((__nothrow__ ));
extern double wcstod (const wchar_t *__restrict __nptr,
        wchar_t **__restrict __endptr) __attribute__ ((__nothrow__ ));



extern float wcstof (const wchar_t *__restrict __nptr,
       wchar_t **__restrict __endptr) __attribute__ ((__nothrow__ ));
extern long double wcstold (const wchar_t *__restrict __nptr,
       wchar_t **__restrict __endptr) __attribute__ ((__nothrow__ ));
extern long int wcstol (const wchar_t *__restrict __nptr,
   wchar_t **__restrict __endptr, int __base) __attribute__ ((__nothrow__ ));



extern unsigned long int wcstoul (const wchar_t *__restrict __nptr,
      wchar_t **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__ ));




__extension__
extern long long int wcstoll (const wchar_t *__restrict __nptr,
         wchar_t **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__ ));



__extension__
extern unsigned long long int wcstoull (const wchar_t *__restrict __nptr,
     wchar_t **__restrict __endptr,
     int __base) __attribute__ ((__nothrow__ ));
extern wchar_t *wcpcpy (wchar_t *__restrict __dest,
   const wchar_t *__restrict __src) __attribute__ ((__nothrow__ ));



extern wchar_t *wcpncpy (wchar_t *__restrict __dest,
    const wchar_t *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__ ));
extern __FILE *open_wmemstream (wchar_t **__bufloc, size_t *__sizeloc) __attribute__ ((__nothrow__ ));





extern int fwide (__FILE *__fp, int __mode) __attribute__ ((__nothrow__ ));






extern int fwprintf (__FILE *__restrict __stream,
       const wchar_t *__restrict __format, ...)
                                                           ;




extern int wprintf (const wchar_t *__restrict __format, ...)
                                                           ;

extern int swprintf (wchar_t *__restrict __s, size_t __n,
       const wchar_t *__restrict __format, ...)
     __attribute__ ((__nothrow__ )) ;





extern int vfwprintf (__FILE *__restrict __s,
        const wchar_t *__restrict __format,
        __gnuc_va_list __arg)
                                                           ;




extern int vwprintf (const wchar_t *__restrict __format,
       __gnuc_va_list __arg)
                                                           ;


extern int vswprintf (wchar_t *__restrict __s, size_t __n,
        const wchar_t *__restrict __format,
        __gnuc_va_list __arg)
     __attribute__ ((__nothrow__ )) ;






extern int fwscanf (__FILE *__restrict __stream,
      const wchar_t *__restrict __format, ...)
                                                          ;




extern int wscanf (const wchar_t *__restrict __format, ...)
                                                          ;

extern int swscanf (const wchar_t *__restrict __s,
      const wchar_t *__restrict __format, ...)
     __attribute__ ((__nothrow__ )) ;






extern int fwscanf (__FILE *__restrict __stream, const wchar_t *__restrict __format, ...) __asm__ ("" "__isoc99_fwscanf")


                                                          ;
extern int wscanf (const wchar_t *__restrict __format, ...) __asm__ ("" "__isoc99_wscanf")

                                                          ;
extern int swscanf (const wchar_t *__restrict __s, const wchar_t *__restrict __format, ...) __asm__ ("" "__isoc99_swscanf") __attribute__ ((__nothrow__ ))


                                                          ;
extern int vfwscanf (__FILE *__restrict __s,
       const wchar_t *__restrict __format,
       __gnuc_va_list __arg)
                                                          ;




extern int vwscanf (const wchar_t *__restrict __format,
      __gnuc_va_list __arg)
                                                          ;

extern int vswscanf (const wchar_t *__restrict __s,
       const wchar_t *__restrict __format,
       __gnuc_va_list __arg)
     __attribute__ ((__nothrow__ )) ;






extern int vfwscanf (__FILE *__restrict __s, const wchar_t *__restrict __format, __gnuc_va_list __arg) __asm__ ("" "__isoc99_vfwscanf")


                                                          ;
extern int vwscanf (const wchar_t *__restrict __format, __gnuc_va_list __arg) __asm__ ("" "__isoc99_vwscanf")

                                                          ;
extern int vswscanf (const wchar_t *__restrict __s, const wchar_t *__restrict __format, __gnuc_va_list __arg) __asm__ ("" "__isoc99_vswscanf") __attribute__ ((__nothrow__ ))


                                                          ;
extern wint_t fgetwc (__FILE *__stream);
extern wint_t getwc (__FILE *__stream);





extern wint_t getwchar (void);






extern wint_t fputwc (wchar_t __wc, __FILE *__stream);
extern wint_t putwc (wchar_t __wc, __FILE *__stream);





extern wint_t putwchar (wchar_t __wc);







extern wchar_t *fgetws (wchar_t *__restrict __ws, int __n,
   __FILE *__restrict __stream);





extern int fputws (const wchar_t *__restrict __ws,
     __FILE *__restrict __stream);






extern wint_t ungetwc (wint_t __wc, __FILE *__stream);
extern size_t wcsftime (wchar_t *__restrict __s, size_t __maxsize,
   const wchar_t *__restrict __format,
   const struct tm *__restrict __tp) __attribute__ ((__nothrow__ ));
typedef struct TMT TMT;

typedef enum{
    TMT_COLOR_DEFAULT = -1,
    TMT_COLOR_BLACK = 1,
    TMT_COLOR_RED,
    TMT_COLOR_GREEN,
    TMT_COLOR_YELLOW,
    TMT_COLOR_BLUE,
    TMT_COLOR_MAGENTA,
    TMT_COLOR_CYAN,
    TMT_COLOR_WHITE,
    TMT_COLOR_MAX
} tmt_color_t;

typedef struct TMTATTRS TMTATTRS;
struct TMTATTRS{
    _Bool bold;
    _Bool dim;
    _Bool underline;
    _Bool blink;
    _Bool reverse;
    _Bool invisible;
    tmt_color_t fg;
    tmt_color_t bg;
};

typedef struct TMTCHAR TMTCHAR;
struct TMTCHAR{
    wchar_t c;
    TMTATTRS a;
};

typedef struct TMTPOINT TMTPOINT;
struct TMTPOINT{
    size_t r;
    size_t c;
};

typedef struct TMTLINE TMTLINE;
struct TMTLINE{
    _Bool dirty;
    TMTCHAR chars[];
};

typedef struct TMTSCREEN TMTSCREEN;
struct TMTSCREEN{
    size_t nline;
    size_t ncol;

    TMTLINE **lines;
};


typedef enum{
    TMT_MSG_MOVED,
    TMT_MSG_UPDATE,
    TMT_MSG_ANSWER,
    TMT_MSG_BELL,
    TMT_MSG_CURSOR
} tmt_msg_t;

typedef void (*TMTCALLBACK)(tmt_msg_t m, struct TMT *v, const void *r, void *p);


TMT *tmt_open(size_t nline, size_t ncol, TMTCALLBACK cb, void *p,
              const wchar_t *acs);
void tmt_close(TMT *vt);
_Bool tmt_resize(TMT *vt, size_t nline, size_t ncol);
void tmt_write(TMT *vt, const char *s, size_t n);
const TMTSCREEN *tmt_screen(const TMT *vt);
const TMTPOINT *tmt_cursor(const TMT *vt);
void tmt_clean(TMT *vt);
void tmt_reset(TMT *vt);





typedef unsigned char __u_char;
typedef unsigned short int __u_short;
typedef unsigned int __u_int;
typedef unsigned long int __u_long;


typedef signed char __int8_t;
typedef unsigned char __uint8_t;
typedef signed short int __int16_t;
typedef unsigned short int __uint16_t;
typedef signed int __int32_t;
typedef unsigned int __uint32_t;

typedef signed long int __int64_t;
typedef unsigned long int __uint64_t;






typedef __int8_t __int_least8_t;
typedef __uint8_t __uint_least8_t;
typedef __int16_t __int_least16_t;
typedef __uint16_t __uint_least16_t;
typedef __int32_t __int_least32_t;
typedef __uint32_t __uint_least32_t;
typedef __int64_t __int_least64_t;
typedef __uint64_t __uint_least64_t;



typedef long int __quad_t;
typedef unsigned long int __u_quad_t;







typedef long int __intmax_t;
typedef unsigned long int __uintmax_t;


typedef unsigned long int __dev_t;
typedef unsigned int __uid_t;
typedef unsigned int __gid_t;
typedef unsigned long int __ino_t;
typedef unsigned long int __ino64_t;
typedef unsigned int __mode_t;
typedef unsigned long int __nlink_t;
typedef long int __off_t;
typedef long int __off64_t;
typedef int __pid_t;
typedef struct { int __val[2]; } __fsid_t;
typedef long int __clock_t;
typedef unsigned long int __rlim_t;
typedef unsigned long int __rlim64_t;
typedef unsigned int __id_t;
typedef long int __time_t;
typedef unsigned int __useconds_t;
typedef long int __suseconds_t;

typedef int __daddr_t;
typedef int __key_t;


typedef int __clockid_t;


typedef void * __timer_t;


typedef long int __blksize_t;




typedef long int __blkcnt_t;
typedef long int __blkcnt64_t;


typedef unsigned long int __fsblkcnt_t;
typedef unsigned long int __fsblkcnt64_t;


typedef unsigned long int __fsfilcnt_t;
typedef unsigned long int __fsfilcnt64_t;


typedef long int __fsword_t;

typedef long int __ssize_t;


typedef long int __syscall_slong_t;

typedef unsigned long int __syscall_ulong_t;



typedef __off64_t __loff_t;
typedef char *__caddr_t;


typedef long int __intptr_t;


typedef unsigned int __socklen_t;




typedef int __sig_atomic_t;





typedef __int8_t int8_t;
typedef __int16_t int16_t;
typedef __int32_t int32_t;
typedef __int64_t int64_t;


typedef __uint8_t uint8_t;
typedef __uint16_t uint16_t;
typedef __uint32_t uint32_t;
typedef __uint64_t uint64_t;





typedef __int_least8_t int_least8_t;
typedef __int_least16_t int_least16_t;
typedef __int_least32_t int_least32_t;
typedef __int_least64_t int_least64_t;


typedef __uint_least8_t uint_least8_t;
typedef __uint_least16_t uint_least16_t;
typedef __uint_least32_t uint_least32_t;
typedef __uint_least64_t uint_least64_t;





typedef signed char int_fast8_t;

typedef long int int_fast16_t;
typedef long int int_fast32_t;
typedef long int int_fast64_t;
typedef unsigned char uint_fast8_t;

typedef unsigned long int uint_fast16_t;
typedef unsigned long int uint_fast32_t;
typedef unsigned long int uint_fast64_t;
typedef long int intptr_t;


typedef unsigned long int uintptr_t;
typedef __intmax_t intmax_t;
typedef __uintmax_t uintmax_t;










typedef struct _G_fpos_t
{
  __off_t __pos;
  __mbstate_t __state;
} __fpos_t;
typedef struct _G_fpos64_t
{
  __off64_t __pos;
  __mbstate_t __state;
} __fpos64_t;


struct _IO_FILE;
struct _IO_marker;
struct _IO_codecvt;
struct _IO_wide_data;




typedef void _IO_lock_t;





struct _IO_FILE
{
  int _flags;


  char *_IO_read_ptr;
  char *_IO_read_end;
  char *_IO_read_base;
  char *_IO_write_base;
  char *_IO_write_ptr;
  char *_IO_write_end;
  char *_IO_buf_base;
  char *_IO_buf_end;


  char *_IO_save_base;
  char *_IO_backup_base;
  char *_IO_save_end;

  struct _IO_marker *_markers;

  struct _IO_FILE *_chain;

  int _fileno;
  int _flags2;
  __off_t _old_offset;


  unsigned short _cur_column;
  signed char _vtable_offset;
  char _shortbuf[1];

  _IO_lock_t *_lock;







  __off64_t _offset;

  struct _IO_codecvt *_codecvt;
  struct _IO_wide_data *_wide_data;
  struct _IO_FILE *_freeres_list;
  void *_freeres_buf;
  size_t __pad5;
  int _mode;

  char _unused2[15 * sizeof (int) - 4 * sizeof (void *) - sizeof (size_t)];
};








typedef __gnuc_va_list va_list;
typedef __off_t off_t;
typedef __ssize_t ssize_t;






typedef __fpos_t fpos_t;



extern FILE *stdin;
extern FILE *stdout;
extern FILE *stderr;






extern int remove (const char *__filename) __attribute__ ((__nothrow__ ));

extern int rename (const char *__old, const char *__new) __attribute__ ((__nothrow__ ));



extern int renameat (int __oldfd, const char *__old, int __newfd,
       const char *__new) __attribute__ ((__nothrow__ ));
extern FILE *tmpfile (void) ;
extern char *tmpnam (char *__s) __attribute__ ((__nothrow__ )) ;




extern char *tmpnam_r (char *__s) __attribute__ ((__nothrow__ )) ;
extern char *tempnam (const char *__dir, const char *__pfx)
     __attribute__ ((__nothrow__ )) __attribute__ ((__malloc__)) ;







extern int fclose (FILE *__stream);




extern int fflush (FILE *__stream);
extern int fflush_unlocked (FILE *__stream);
extern FILE *fopen (const char *__restrict __filename,
      const char *__restrict __modes) ;




extern FILE *freopen (const char *__restrict __filename,
        const char *__restrict __modes,
        FILE *__restrict __stream) ;
extern FILE *fdopen (int __fd, const char *__modes) __attribute__ ((__nothrow__ )) ;
extern FILE *fmemopen (void *__s, size_t __len, const char *__modes)
  __attribute__ ((__nothrow__ )) ;




extern FILE *open_memstream (char **__bufloc, size_t *__sizeloc) __attribute__ ((__nothrow__ )) ;





extern void setbuf (FILE *__restrict __stream, char *__restrict __buf) __attribute__ ((__nothrow__ ));



extern int setvbuf (FILE *__restrict __stream, char *__restrict __buf,
      int __modes, size_t __n) __attribute__ ((__nothrow__ ));




extern void setbuffer (FILE *__restrict __stream, char *__restrict __buf,
         size_t __size) __attribute__ ((__nothrow__ ));


extern void setlinebuf (FILE *__stream) __attribute__ ((__nothrow__ ));







extern int fprintf (FILE *__restrict __stream,
      const char *__restrict __format, ...);




extern int printf (const char *__restrict __format, ...);

extern int sprintf (char *__restrict __s,
      const char *__restrict __format, ...) __attribute__ ((__nothrow__));





extern int vfprintf (FILE *__restrict __s, const char *__restrict __format,
       __gnuc_va_list __arg);




extern int vprintf (const char *__restrict __format, __gnuc_va_list __arg);

extern int vsprintf (char *__restrict __s, const char *__restrict __format,
       __gnuc_va_list __arg) __attribute__ ((__nothrow__));



extern int snprintf (char *__restrict __s, size_t __maxlen,
       const char *__restrict __format, ...)
     __attribute__ ((__nothrow__)) __attribute__ ((__format__ (__printf__, 3, 4)));

extern int vsnprintf (char *__restrict __s, size_t __maxlen,
        const char *__restrict __format, __gnuc_va_list __arg)
     __attribute__ ((__nothrow__)) __attribute__ ((__format__ (__printf__, 3, 0)));
extern int vdprintf (int __fd, const char *__restrict __fmt,
       __gnuc_va_list __arg)
     __attribute__ ((__format__ (__printf__, 2, 0)));
extern int dprintf (int __fd, const char *__restrict __fmt, ...)
     __attribute__ ((__format__ (__printf__, 2, 3)));







extern int fscanf (FILE *__restrict __stream,
     const char *__restrict __format, ...) ;




extern int scanf (const char *__restrict __format, ...) ;

extern int sscanf (const char *__restrict __s,
     const char *__restrict __format, ...) __attribute__ ((__nothrow__ ));






extern int fscanf (FILE *__restrict __stream, const char *__restrict __format, ...) __asm__ ("" "__isoc99_fscanf") ;


extern int scanf (const char *__restrict __format, ...) __asm__ ("" "__isoc99_scanf") ;

extern int sscanf (const char *__restrict __s, const char *__restrict __format, ...) __asm__ ("" "__isoc99_sscanf") __attribute__ ((__nothrow__ ));
extern int vfscanf (FILE *__restrict __s, const char *__restrict __format,
      __gnuc_va_list __arg)
     __attribute__ ((__format__ (__scanf__, 2, 0))) ;





extern int vscanf (const char *__restrict __format, __gnuc_va_list __arg)
     __attribute__ ((__format__ (__scanf__, 1, 0))) ;


extern int vsscanf (const char *__restrict __s,
      const char *__restrict __format, __gnuc_va_list __arg)
     __attribute__ ((__nothrow__ )) __attribute__ ((__format__ (__scanf__, 2, 0)));




extern int vfscanf (FILE *__restrict __s, const char *__restrict __format, __gnuc_va_list __arg) __asm__ ("" "__isoc99_vfscanf")



     __attribute__ ((__format__ (__scanf__, 2, 0))) ;
extern int vscanf (const char *__restrict __format, __gnuc_va_list __arg) __asm__ ("" "__isoc99_vscanf")

     __attribute__ ((__format__ (__scanf__, 1, 0))) ;
extern int vsscanf (const char *__restrict __s, const char *__restrict __format, __gnuc_va_list __arg) __asm__ ("" "__isoc99_vsscanf") __attribute__ ((__nothrow__ ))



     __attribute__ ((__format__ (__scanf__, 2, 0)));
extern int fgetc (FILE *__stream);
extern int getc (FILE *__stream);





extern int getchar (void);






extern int getc_unlocked (FILE *__stream);
extern int getchar_unlocked (void);
extern int fgetc_unlocked (FILE *__stream);
extern int fputc (int __c, FILE *__stream);
extern int putc (int __c, FILE *__stream);





extern int putchar (int __c);
extern int fputc_unlocked (int __c, FILE *__stream);







extern int putc_unlocked (int __c, FILE *__stream);
extern int putchar_unlocked (int __c);






extern int getw (FILE *__stream);


extern int putw (int __w, FILE *__stream);







extern char *fgets (char *__restrict __s, int __n, FILE *__restrict __stream)
          ;
extern __ssize_t __getdelim (char **__restrict __lineptr,
                             size_t *__restrict __n, int __delimiter,
                             FILE *__restrict __stream) ;
extern __ssize_t getdelim (char **__restrict __lineptr,
                           size_t *__restrict __n, int __delimiter,
                           FILE *__restrict __stream) ;







extern __ssize_t getline (char **__restrict __lineptr,
                          size_t *__restrict __n,
                          FILE *__restrict __stream) ;







extern int fputs (const char *__restrict __s, FILE *__restrict __stream);





extern int puts (const char *__s);






extern int ungetc (int __c, FILE *__stream);






extern size_t fread (void *__restrict __ptr, size_t __size,
       size_t __n, FILE *__restrict __stream) ;




extern size_t fwrite (const void *__restrict __ptr, size_t __size,
        size_t __n, FILE *__restrict __s);
extern size_t fread_unlocked (void *__restrict __ptr, size_t __size,
         size_t __n, FILE *__restrict __stream) ;
extern size_t fwrite_unlocked (const void *__restrict __ptr, size_t __size,
          size_t __n, FILE *__restrict __stream);







extern int fseek (FILE *__stream, long int __off, int __whence);




extern long int ftell (FILE *__stream) ;




extern void rewind (FILE *__stream);
extern int fseeko (FILE *__stream, __off_t __off, int __whence);




extern __off_t ftello (FILE *__stream) ;
extern int fgetpos (FILE *__restrict __stream, fpos_t *__restrict __pos);




extern int fsetpos (FILE *__stream, const fpos_t *__pos);
extern void clearerr (FILE *__stream) __attribute__ ((__nothrow__ ));

extern int feof (FILE *__stream) __attribute__ ((__nothrow__ )) ;

extern int ferror (FILE *__stream) __attribute__ ((__nothrow__ )) ;



extern void clearerr_unlocked (FILE *__stream) __attribute__ ((__nothrow__ ));
extern int feof_unlocked (FILE *__stream) __attribute__ ((__nothrow__ )) ;
extern int ferror_unlocked (FILE *__stream) __attribute__ ((__nothrow__ )) ;







extern void perror (const char *__s);






extern int sys_nerr;
extern const char *const sys_errlist[];




extern int fileno (FILE *__stream) __attribute__ ((__nothrow__ )) ;




extern int fileno_unlocked (FILE *__stream) __attribute__ ((__nothrow__ )) ;
extern FILE *popen (const char *__command, const char *__modes) ;





extern int pclose (FILE *__stream);





extern char *ctermid (char *__s) __attribute__ ((__nothrow__ ));
extern void flockfile (FILE *__stream) __attribute__ ((__nothrow__ ));



extern int ftrylockfile (FILE *__stream) __attribute__ ((__nothrow__ )) ;


extern void funlockfile (FILE *__stream) __attribute__ ((__nothrow__ ));
extern int __uflow (FILE *);
extern int __overflow (FILE *, int);












typedef enum
{
  P_ALL,
  P_PID,
  P_PGID
} idtype_t;
typedef struct
  {
    int quot;
    int rem;
  } div_t;



typedef struct
  {
    long int quot;
    long int rem;
  } ldiv_t;





__extension__ typedef struct
  {
    long long int quot;
    long long int rem;
  } lldiv_t;
extern size_t __ctype_get_mb_cur_max (void) __attribute__ ((__nothrow__ )) ;



extern double atof (const char *__nptr)
     __attribute__ ((__nothrow__ )) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;

extern int atoi (const char *__nptr)
     __attribute__ ((__nothrow__ )) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;

extern long int atol (const char *__nptr)
     __attribute__ ((__nothrow__ )) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;



__extension__ extern long long int atoll (const char *__nptr)
     __attribute__ ((__nothrow__ )) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;



extern double strtod (const char *__restrict __nptr,
        char **__restrict __endptr)
     __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (1)));



extern float strtof (const char *__restrict __nptr,
       char **__restrict __endptr) __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (1)));

extern long double strtold (const char *__restrict __nptr,
       char **__restrict __endptr)
     __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (1)));
extern long int strtol (const char *__restrict __nptr,
   char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (1)));

extern unsigned long int strtoul (const char *__restrict __nptr,
      char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (1)));



__extension__
extern long long int strtoq (const char *__restrict __nptr,
        char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (1)));

__extension__
extern unsigned long long int strtouq (const char *__restrict __nptr,
           char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (1)));




__extension__
extern long long int strtoll (const char *__restrict __nptr,
         char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (1)));

__extension__
extern unsigned long long int strtoull (const char *__restrict __nptr,
     char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (1)));
extern char *l64a (long int __n) __attribute__ ((__nothrow__ )) ;


extern long int a64l (const char *__s)
     __attribute__ ((__nothrow__ )) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;





typedef __u_char u_char;
typedef __u_short u_short;
typedef __u_int u_int;
typedef __u_long u_long;
typedef __quad_t quad_t;
typedef __u_quad_t u_quad_t;
typedef __fsid_t fsid_t;


typedef __loff_t loff_t;




typedef __ino_t ino_t;
typedef __dev_t dev_t;




typedef __gid_t gid_t;




typedef __mode_t mode_t;




typedef __nlink_t nlink_t;




typedef __uid_t uid_t;
typedef __pid_t pid_t;





typedef __id_t id_t;
typedef __daddr_t daddr_t;
typedef __caddr_t caddr_t;





typedef __key_t key_t;











typedef __clock_t clock_t;







typedef __clockid_t clockid_t;






typedef __time_t time_t;






typedef __timer_t timer_t;



typedef unsigned long int ulong;
typedef unsigned short int ushort;
typedef unsigned int uint;







typedef __uint8_t u_int8_t;
typedef __uint16_t u_int16_t;
typedef __uint32_t u_int32_t;
typedef __uint64_t u_int64_t;


typedef int register_t __attribute__ ((__mode__ (__word__)));
static __inline __uint16_t
__bswap_16 (__uint16_t __bsx)
{



  return ((__uint16_t) ((((__bsx) >> 8) & 0xff) | (((__bsx) & 0xff) << 8)));

}






static __inline __uint32_t
__bswap_32 (__uint32_t __bsx)
{



  return ((((__bsx) & 0xff000000u) >> 24) | (((__bsx) & 0x00ff0000u) >> 8) | (((__bsx) & 0x0000ff00u) << 8) | (((__bsx) & 0x000000ffu) << 24));

}
__extension__ static __inline __uint64_t
__bswap_64 (__uint64_t __bsx)
{



  return ((((__bsx) & 0xff00000000000000ull) >> 56) | (((__bsx) & 0x00ff000000000000ull) >> 40) | (((__bsx) & 0x0000ff0000000000ull) >> 24) | (((__bsx) & 0x000000ff00000000ull) >> 8) | (((__bsx) & 0x00000000ff000000ull) << 8) | (((__bsx) & 0x0000000000ff0000ull) << 24) | (((__bsx) & 0x000000000000ff00ull) << 40) | (((__bsx) & 0x00000000000000ffull) << 56));

}
static __inline __uint16_t
__uint16_identity (__uint16_t __x)
{
  return __x;
}

static __inline __uint32_t
__uint32_identity (__uint32_t __x)
{
  return __x;
}

static __inline __uint64_t
__uint64_identity (__uint64_t __x)
{
  return __x;
}











typedef struct
{
  unsigned long int __val[(1024 / (8 * sizeof (unsigned long int)))];
} __sigset_t;


typedef __sigset_t sigset_t;










struct timeval
{
  __time_t tv_sec;
  __suseconds_t tv_usec;
};

struct timespec
{
  __time_t tv_sec;



  __syscall_slong_t tv_nsec;
};



typedef __suseconds_t suseconds_t;





typedef long int __fd_mask;
typedef struct
  {






    __fd_mask __fds_bits[1024 / (8 * (int) sizeof (__fd_mask))];


  } fd_set;






typedef __fd_mask fd_mask;
extern int select (int __nfds, fd_set *__restrict __readfds,
     fd_set *__restrict __writefds,
     fd_set *__restrict __exceptfds,
     struct timeval *__restrict __timeout);
extern int pselect (int __nfds, fd_set *__restrict __readfds,
      fd_set *__restrict __writefds,
      fd_set *__restrict __exceptfds,
      const struct timespec *__restrict __timeout,
      const __sigset_t *__restrict __sigmask);





typedef __blksize_t blksize_t;






typedef __blkcnt_t blkcnt_t;



typedef __fsblkcnt_t fsblkcnt_t;



typedef __fsfilcnt_t fsfilcnt_t;




typedef struct __pthread_internal_list
{
  struct __pthread_internal_list *__prev;
  struct __pthread_internal_list *__next;
} __pthread_list_t;

typedef struct __pthread_internal_slist
{
  struct __pthread_internal_slist *__next;
} __pthread_slist_t;
struct __pthread_mutex_s
{
  int __lock;
  unsigned int __count;
  int __owner;

  unsigned int __nusers;



  int __kind;

  short __spins;
  short __elision;
  __pthread_list_t __list;
};
struct __pthread_rwlock_arch_t
{
  unsigned int __readers;
  unsigned int __writers;
  unsigned int __wrphase_futex;
  unsigned int __writers_futex;
  unsigned int __pad3;
  unsigned int __pad4;

  int __cur_writer;
  int __shared;
  signed char __rwelision;




  unsigned char __pad1[7];


  unsigned long int __pad2;


  unsigned int __flags;
};




struct __pthread_cond_s
{
  __extension__ union
  {
    __extension__ unsigned long long int __wseq;
    struct
    {
      unsigned int __low;
      unsigned int __high;
    } __wseq32;
  };
  __extension__ union
  {
    __extension__ unsigned long long int __g1_start;
    struct
    {
      unsigned int __low;
      unsigned int __high;
    } __g1_start32;
  };
  unsigned int __g_refs[2] ;
  unsigned int __g_size[2];
  unsigned int __g1_orig_size;
  unsigned int __wrefs;
  unsigned int __g_signals[2];
};



typedef unsigned long int pthread_t;




typedef union
{
  char __size[4];
  int __align;
} pthread_mutexattr_t;




typedef union
{
  char __size[4];
  int __align;
} pthread_condattr_t;



typedef unsigned int pthread_key_t;



typedef int pthread_once_t;


union pthread_attr_t
{
  char __size[56];
  long int __align;
};

typedef union pthread_attr_t pthread_attr_t;




typedef union
{
  struct __pthread_mutex_s __data;
  char __size[40];
  long int __align;
} pthread_mutex_t;


typedef union
{
  struct __pthread_cond_s __data;
  char __size[48];
  __extension__ long long int __align;
} pthread_cond_t;





typedef union
{
  struct __pthread_rwlock_arch_t __data;
  char __size[56];
  long int __align;
} pthread_rwlock_t;

typedef union
{
  char __size[8];
  long int __align;
} pthread_rwlockattr_t;





typedef volatile int pthread_spinlock_t;




typedef union
{
  char __size[32];
  long int __align;
} pthread_barrier_t;

typedef union
{
  char __size[4];
  int __align;
} pthread_barrierattr_t;






extern long int random (void) __attribute__ ((__nothrow__ ));


extern void srandom (unsigned int __seed) __attribute__ ((__nothrow__ ));





extern char *initstate (unsigned int __seed, char *__statebuf,
   size_t __statelen) __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (2)));



extern char *setstate (char *__statebuf) __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (1)));







struct random_data
  {
    int32_t *fptr;
    int32_t *rptr;
    int32_t *state;
    int rand_type;
    int rand_deg;
    int rand_sep;
    int32_t *end_ptr;
  };

extern int random_r (struct random_data *__restrict __buf,
       int32_t *__restrict __result) __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (1, 2)));

extern int srandom_r (unsigned int __seed, struct random_data *__buf)
     __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (2)));

extern int initstate_r (unsigned int __seed, char *__restrict __statebuf,
   size_t __statelen,
   struct random_data *__restrict __buf)
     __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (2, 4)));

extern int setstate_r (char *__restrict __statebuf,
         struct random_data *__restrict __buf)
     __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (1, 2)));





extern int rand (void) __attribute__ ((__nothrow__ ));

extern void srand (unsigned int __seed) __attribute__ ((__nothrow__ ));



extern int rand_r (unsigned int *__seed) __attribute__ ((__nothrow__ ));







extern double drand48 (void) __attribute__ ((__nothrow__ ));
extern double erand48 (unsigned short int __xsubi[3]) __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (1)));


extern long int lrand48 (void) __attribute__ ((__nothrow__ ));
extern long int nrand48 (unsigned short int __xsubi[3])
     __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (1)));


extern long int mrand48 (void) __attribute__ ((__nothrow__ ));
extern long int jrand48 (unsigned short int __xsubi[3])
     __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (1)));


extern void srand48 (long int __seedval) __attribute__ ((__nothrow__ ));
extern unsigned short int *seed48 (unsigned short int __seed16v[3])
     __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (1)));
extern void lcong48 (unsigned short int __param[7]) __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (1)));





struct drand48_data
  {
    unsigned short int __x[3];
    unsigned short int __old_x[3];
    unsigned short int __c;
    unsigned short int __init;
    __extension__ unsigned long long int __a;

  };


extern int drand48_r (struct drand48_data *__restrict __buffer,
        double *__restrict __result) __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (1, 2)));
extern int erand48_r (unsigned short int __xsubi[3],
        struct drand48_data *__restrict __buffer,
        double *__restrict __result) __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (1, 2)));


extern int lrand48_r (struct drand48_data *__restrict __buffer,
        long int *__restrict __result)
     __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (1, 2)));
extern int nrand48_r (unsigned short int __xsubi[3],
        struct drand48_data *__restrict __buffer,
        long int *__restrict __result)
     __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (1, 2)));


extern int mrand48_r (struct drand48_data *__restrict __buffer,
        long int *__restrict __result)
     __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (1, 2)));
extern int jrand48_r (unsigned short int __xsubi[3],
        struct drand48_data *__restrict __buffer,
        long int *__restrict __result)
     __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (1, 2)));


extern int srand48_r (long int __seedval, struct drand48_data *__buffer)
     __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (2)));

extern int seed48_r (unsigned short int __seed16v[3],
       struct drand48_data *__buffer) __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (1, 2)));

extern int lcong48_r (unsigned short int __param[7],
        struct drand48_data *__buffer)
     __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (1, 2)));




extern void *malloc (size_t __size) __attribute__ ((__nothrow__ )) __attribute__ ((__malloc__))
                                         ;

extern void *calloc (size_t __nmemb, size_t __size)
     __attribute__ ((__nothrow__ )) __attribute__ ((__malloc__)) ;






extern void *realloc (void *__ptr, size_t __size)
     __attribute__ ((__nothrow__ )) __attribute__ ((__warn_unused_result__)) ;







extern void *reallocarray (void *__ptr, size_t __nmemb, size_t __size)
     __attribute__ ((__nothrow__ )) __attribute__ ((__warn_unused_result__))
                                      ;



extern void free (void *__ptr) __attribute__ ((__nothrow__ ));










extern void *alloca (size_t __size) __attribute__ ((__nothrow__ ));





extern void *valloc (size_t __size) __attribute__ ((__nothrow__ )) __attribute__ ((__malloc__))
                                         ;




extern int posix_memalign (void **__memptr, size_t __alignment, size_t __size)
     __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (1))) ;




extern void *aligned_alloc (size_t __alignment, size_t __size)
     __attribute__ ((__nothrow__ )) __attribute__ ((__malloc__)) ;



extern void abort (void) __attribute__ ((__nothrow__ )) __attribute__ ((__noreturn__));



extern int atexit (void (*__func) (void)) __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (1)));







extern int at_quick_exit (void (*__func) (void)) __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (1)));






extern int on_exit (void (*__func) (int __status, void *__arg), void *__arg)
     __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (1)));





extern void exit (int __status) __attribute__ ((__nothrow__ )) __attribute__ ((__noreturn__));





extern void quick_exit (int __status) __attribute__ ((__nothrow__ )) __attribute__ ((__noreturn__));





extern void _Exit (int __status) __attribute__ ((__nothrow__ )) __attribute__ ((__noreturn__));




extern char *getenv (const char *__name) __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (1))) ;
extern int putenv (char *__string) __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (1)));





extern int setenv (const char *__name, const char *__value, int __replace)
     __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (2)));


extern int unsetenv (const char *__name) __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (1)));






extern int clearenv (void) __attribute__ ((__nothrow__ ));
extern char *mktemp (char *__template) __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (1)));
extern int mkstemp (char *__template) __attribute__ ((__nonnull__ (1))) ;
extern int mkstemps (char *__template, int __suffixlen) __attribute__ ((__nonnull__ (1))) ;
extern char *mkdtemp (char *__template) __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (1))) ;
extern int system (const char *__command) ;
extern char *realpath (const char *__restrict __name,
         char *__restrict __resolved) __attribute__ ((__nothrow__ )) ;






typedef int (*__compar_fn_t) (const void *, const void *);
extern void *bsearch (const void *__key, const void *__base,
        size_t __nmemb, size_t __size, __compar_fn_t __compar)
     __attribute__ ((__nonnull__ (1, 2, 5))) ;







extern void qsort (void *__base, size_t __nmemb, size_t __size,
     __compar_fn_t __compar) __attribute__ ((__nonnull__ (1, 4)));
extern int abs (int __x) __attribute__ ((__nothrow__ )) __attribute__ ((__const__)) ;
extern long int labs (long int __x) __attribute__ ((__nothrow__ )) __attribute__ ((__const__)) ;


__extension__ extern long long int llabs (long long int __x)
     __attribute__ ((__nothrow__ )) __attribute__ ((__const__)) ;






extern div_t div (int __numer, int __denom)
     __attribute__ ((__nothrow__ )) __attribute__ ((__const__)) ;
extern ldiv_t ldiv (long int __numer, long int __denom)
     __attribute__ ((__nothrow__ )) __attribute__ ((__const__)) ;


__extension__ extern lldiv_t lldiv (long long int __numer,
        long long int __denom)
     __attribute__ ((__nothrow__ )) __attribute__ ((__const__)) ;
extern char *ecvt (double __value, int __ndigit, int *__restrict __decpt,
     int *__restrict __sign) __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (3, 4))) ;




extern char *fcvt (double __value, int __ndigit, int *__restrict __decpt,
     int *__restrict __sign) __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (3, 4))) ;




extern char *gcvt (double __value, int __ndigit, char *__buf)
     __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (3))) ;




extern char *qecvt (long double __value, int __ndigit,
      int *__restrict __decpt, int *__restrict __sign)
     __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (3, 4))) ;
extern char *qfcvt (long double __value, int __ndigit,
      int *__restrict __decpt, int *__restrict __sign)
     __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (3, 4))) ;
extern char *qgcvt (long double __value, int __ndigit, char *__buf)
     __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (3))) ;




extern int ecvt_r (double __value, int __ndigit, int *__restrict __decpt,
     int *__restrict __sign, char *__restrict __buf,
     size_t __len) __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (3, 4, 5)));
extern int fcvt_r (double __value, int __ndigit, int *__restrict __decpt,
     int *__restrict __sign, char *__restrict __buf,
     size_t __len) __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (3, 4, 5)));

extern int qecvt_r (long double __value, int __ndigit,
      int *__restrict __decpt, int *__restrict __sign,
      char *__restrict __buf, size_t __len)
     __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (3, 4, 5)));
extern int qfcvt_r (long double __value, int __ndigit,
      int *__restrict __decpt, int *__restrict __sign,
      char *__restrict __buf, size_t __len)
     __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (3, 4, 5)));





extern int mblen (const char *__s, size_t __n) __attribute__ ((__nothrow__ ));


extern int mbtowc (wchar_t *__restrict __pwc,
     const char *__restrict __s, size_t __n) __attribute__ ((__nothrow__ ));


extern int wctomb (char *__s, wchar_t __wchar) __attribute__ ((__nothrow__ ));



extern size_t mbstowcs (wchar_t *__restrict __pwcs,
   const char *__restrict __s, size_t __n) __attribute__ ((__nothrow__ ));

extern size_t wcstombs (char *__restrict __s,
   const wchar_t *__restrict __pwcs, size_t __n)
     __attribute__ ((__nothrow__ ));







extern int rpmatch (const char *__response) __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (1))) ;
extern int getsubopt (char **__restrict __optionp,
        char *const *__restrict __tokens,
        char **__restrict __valuep)
     __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (1, 2, 3))) ;
extern int getloadavg (double __loadavg[], int __nelem)
     __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (1)));






extern void *memcpy (void *__restrict __dest, const void *__restrict __src,
       size_t __n) __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (1, 2)));


extern void *memmove (void *__dest, const void *__src, size_t __n)
     __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (1, 2)));





extern void *memccpy (void *__restrict __dest, const void *__restrict __src,
        int __c, size_t __n)
     __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (1, 2)));




extern void *memset (void *__s, int __c, size_t __n) __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (1)));


extern int memcmp (const void *__s1, const void *__s2, size_t __n)
     __attribute__ ((__nothrow__ )) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern void *memchr (const void *__s, int __c, size_t __n)
      __attribute__ ((__nothrow__ )) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
extern char *strcpy (char *__restrict __dest, const char *__restrict __src)
     __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (1, 2)));

extern char *strncpy (char *__restrict __dest,
        const char *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (1, 2)));


extern char *strcat (char *__restrict __dest, const char *__restrict __src)
     __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (1, 2)));

extern char *strncat (char *__restrict __dest, const char *__restrict __src,
        size_t __n) __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (1, 2)));


extern int strcmp (const char *__s1, const char *__s2)
     __attribute__ ((__nothrow__ )) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));

extern int strncmp (const char *__s1, const char *__s2, size_t __n)
     __attribute__ ((__nothrow__ )) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));


extern int strcoll (const char *__s1, const char *__s2)
     __attribute__ ((__nothrow__ )) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));

extern size_t strxfrm (char *__restrict __dest,
         const char *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (2)));






extern int strcoll_l (const char *__s1, const char *__s2, locale_t __l)
     __attribute__ ((__nothrow__ )) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2, 3)));


extern size_t strxfrm_l (char *__dest, const char *__src, size_t __n,
    locale_t __l) __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (2, 4)));





extern char *strdup (const char *__s)
     __attribute__ ((__nothrow__ )) __attribute__ ((__malloc__)) __attribute__ ((__nonnull__ (1)));






extern char *strndup (const char *__string, size_t __n)
     __attribute__ ((__nothrow__ )) __attribute__ ((__malloc__)) __attribute__ ((__nonnull__ (1)));
extern char *strchr (const char *__s, int __c)
     __attribute__ ((__nothrow__ )) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
extern char *strrchr (const char *__s, int __c)
     __attribute__ ((__nothrow__ )) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
extern size_t strcspn (const char *__s, const char *__reject)
     __attribute__ ((__nothrow__ )) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));


extern size_t strspn (const char *__s, const char *__accept)
     __attribute__ ((__nothrow__ )) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *strpbrk (const char *__s, const char *__accept)
     __attribute__ ((__nothrow__ )) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *strstr (const char *__haystack, const char *__needle)
     __attribute__ ((__nothrow__ )) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));




extern char *strtok (char *__restrict __s, const char *__restrict __delim)
     __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (2)));



extern char *__strtok_r (char *__restrict __s,
    const char *__restrict __delim,
    char **__restrict __save_ptr)
     __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (2, 3)));

extern char *strtok_r (char *__restrict __s, const char *__restrict __delim,
         char **__restrict __save_ptr)
     __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (2, 3)));
extern size_t strlen (const char *__s)
     __attribute__ ((__nothrow__ )) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));




extern size_t strnlen (const char *__string, size_t __maxlen)
     __attribute__ ((__nothrow__ )) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));




extern char *strerror (int __errnum) __attribute__ ((__nothrow__ ));
extern int strerror_r (int __errnum, char *__buf, size_t __buflen) __asm__ ("" "__xpg_strerror_r") __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (2)));
extern char *strerror_l (int __errnum, locale_t __l) __attribute__ ((__nothrow__ ));




extern int bcmp (const void *__s1, const void *__s2, size_t __n)
     __attribute__ ((__nothrow__ )) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));


extern void bcopy (const void *__src, void *__dest, size_t __n)
  __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (1, 2)));


extern void bzero (void *__s, size_t __n) __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (1)));
extern char *index (const char *__s, int __c)
     __attribute__ ((__nothrow__ )) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
extern char *rindex (const char *__s, int __c)
     __attribute__ ((__nothrow__ )) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));






extern int ffs (int __i) __attribute__ ((__nothrow__ )) __attribute__ ((__const__));





extern int ffsl (long int __l) __attribute__ ((__nothrow__ )) __attribute__ ((__const__));
__extension__ extern int ffsll (long long int __ll)
     __attribute__ ((__nothrow__ )) __attribute__ ((__const__));



extern int strcasecmp (const char *__s1, const char *__s2)
     __attribute__ ((__nothrow__ )) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));


extern int strncasecmp (const char *__s1, const char *__s2, size_t __n)
     __attribute__ ((__nothrow__ )) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));






extern int strcasecmp_l (const char *__s1, const char *__s2, locale_t __loc)
     __attribute__ ((__nothrow__ )) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2, 3)));



extern int strncasecmp_l (const char *__s1, const char *__s2,
     size_t __n, locale_t __loc)
     __attribute__ ((__nothrow__ )) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2, 4)));



extern void explicit_bzero (void *__s, size_t __n) __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (1)));



extern char *strsep (char **__restrict __stringp,
       const char *__restrict __delim)
     __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (1, 2)));




extern char *strsignal (int __sig) __attribute__ ((__nothrow__ ));


extern char *__stpcpy (char *__restrict __dest, const char *__restrict __src)
     __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (1, 2)));
extern char *stpcpy (char *__restrict __dest, const char *__restrict __src)
     __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (1, 2)));



extern char *__stpncpy (char *__restrict __dest,
   const char *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (1, 2)));
extern char *stpncpy (char *__restrict __dest,
        const char *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (1, 2)));
struct TMT{
    TMTPOINT curs, oldcurs;
    TMTATTRS attrs, oldattrs;

    _Bool dirty, acs, ignored;
    TMTSCREEN screen;
    TMTLINE *tabs;

    TMTCALLBACK cb;
    void *p;
    const wchar_t *acschars;

    mbstate_t ms;
    size_t nmb;
    char mb[100 + 1];

    size_t pars[8];
    size_t npar;
    size_t arg;
    enum {S_NUL, S_ESC, S_ARG} state;
};

static TMTATTRS defattrs = {.fg = TMT_COLOR_DEFAULT, .bg = TMT_COLOR_DEFAULT};
static void writecharatcurs(TMT *vt, wchar_t w);

static wchar_t
tacs(const TMT *vt, unsigned char c)
{

    static unsigned char map[] = {0020U, 0021U, 0030U, 0031U, 0333U, 0004U,
                                  0261U, 0370U, 0361U, 0260U, 0331U, 0277U,
                                  0332U, 0300U, 0305U, 0176U, 0304U, 0304U,
                                  0304U, 0137U, 0303U, 0264U, 0301U, 0302U,
                                  0263U, 0363U, 0362U, 0343U, 0330U, 0234U,
                                  0376U};
    for (size_t i = 0; i < sizeof(map); i++) if (map[i] == c)
        return vt->acschars[i];
    return (wchar_t)c;
}

static void
dirtylines(TMT *vt, size_t s, size_t e)
{
    vt->dirty = 1;
    for (size_t i = s; i < e; i++)
        vt->screen.lines[i]->dirty = 1;
}

static void
clearline(TMT *vt, TMTLINE *l, size_t s, size_t e)
{
    vt->dirty = l->dirty = 1;
    for (size_t i = s; i < e && i < vt->screen.ncol; i++){
        l->chars[i].a = defattrs;
        l->chars[i].c = L' ';
    }
}

static void
clearlines(TMT *vt, size_t r, size_t n)
{
    for (size_t i = r; i < r + n && i < vt->screen.nline; i++)
        clearline(vt, vt->screen.lines[i], 0, vt->screen.ncol);
}

static void
scrup(TMT *vt, size_t r, size_t n)
{
    n = (((size_t)(n) < (size_t)(vt->screen.nline - 1 - r)) ? (size_t)(n) : (size_t)(vt->screen.nline - 1 - r));

    if (n){
        TMTLINE *buf[n];

        memcpy(buf, vt->screen.lines + r, n * sizeof(TMTLINE *));
        memmove(vt->screen.lines + r, vt->screen.lines + r + n,
                (vt->screen.nline - n - r) * sizeof(TMTLINE *));
        memcpy(vt->screen.lines + (vt->screen.nline - n),
               buf, n * sizeof(TMTLINE *));

        clearlines(vt, vt->screen.nline - n, n);
        dirtylines(vt, r, vt->screen.nline);
    }
}

static void
scrdn(TMT *vt, size_t r, size_t n)
{
    n = (((size_t)(n) < (size_t)(vt->screen.nline - 1 - r)) ? (size_t)(n) : (size_t)(vt->screen.nline - 1 - r));

    if (n){
        TMTLINE *buf[n];

        memcpy(buf, vt->screen.lines + (vt->screen.nline - n),
               n * sizeof(TMTLINE *));
        memmove(vt->screen.lines + r + n, vt->screen.lines + r,
                (vt->screen.nline - n - r) * sizeof(TMTLINE *));
        memcpy(vt->screen.lines + r, buf, n * sizeof(TMTLINE *));

        clearlines(vt, r, n);
        dirtylines(vt, r, vt->screen.nline);
    }
}

static void ed (TMT *vt) { TMTSCREEN *s = &vt->screen; TMTPOINT *c = &vt->curs; TMTLINE *l = (vt)->screen.lines[(((size_t)((vt)->curs.r) < (size_t)((vt)->screen.nline - 1)) ? (size_t)((vt)->curs.r) : (size_t)((vt)->screen.nline - 1))]; TMTCHAR *t = vt->tabs->chars;
    size_t b = 0;
    size_t e = s->nline;

    switch ((vt->pars[0])){
        case 0: b = c->r + 1; clearline(vt, l, c->c, vt->screen.ncol); break;
        case 1: e = c->r - 1; clearline(vt, l, 0, c->c); break;
        case 2: break;
        default: return;
    }

    clearlines(vt, b, e - b);
}

static void ich (TMT *vt) { TMTSCREEN *s = &vt->screen; TMTPOINT *c = &vt->curs; TMTLINE *l = (vt)->screen.lines[(((size_t)((vt)->curs.r) < (size_t)((vt)->screen.nline - 1)) ? (size_t)((vt)->curs.r) : (size_t)((vt)->screen.nline - 1))]; TMTCHAR *t = vt->tabs->chars;
    size_t n = (vt->pars[0]? vt->pars[0] : 1);
    if (n > s->ncol - c->c - 1) n = s->ncol - c->c - 1;

    memmove(l->chars + c->c + n, l->chars + c->c,
            (((size_t)(s->ncol - 1 - c->c) < (size_t)((s->ncol - c->c - n - 1))) ? (size_t)(s->ncol - 1 - c->c) : (size_t)((s->ncol - c->c - n - 1))) * sizeof(TMTCHAR));

    clearline(vt, l, c->c, n);
}

static void dch (TMT *vt) { TMTSCREEN *s = &vt->screen; TMTPOINT *c = &vt->curs; TMTLINE *l = (vt)->screen.lines[(((size_t)((vt)->curs.r) < (size_t)((vt)->screen.nline - 1)) ? (size_t)((vt)->curs.r) : (size_t)((vt)->screen.nline - 1))]; TMTCHAR *t = vt->tabs->chars;
    size_t n = (vt->pars[0]? vt->pars[0] : 1);
    if (n > s->ncol - c->c) n = s->ncol - c->c;
    else if (n == 0) return;

    memmove(l->chars + c->c, l->chars + c->c + n,
            (s->ncol - c->c - n) * sizeof(TMTCHAR));

    clearline(vt, l, s->ncol - n, s->ncol);




}

static void el (TMT *vt) { TMTSCREEN *s = &vt->screen; TMTPOINT *c = &vt->curs; TMTLINE *l = (vt)->screen.lines[(((size_t)((vt)->curs.r) < (size_t)((vt)->screen.nline - 1)) ? (size_t)((vt)->curs.r) : (size_t)((vt)->screen.nline - 1))]; TMTCHAR *t = vt->tabs->chars;
    switch ((vt->pars[0])){
        case 0: clearline(vt, l, c->c, vt->screen.ncol); break;
        case 1: clearline(vt, l, 0, (((size_t)(c->c + 1) < (size_t)(s->ncol - 1)) ? (size_t)(c->c + 1) : (size_t)(s->ncol - 1))); break;
        case 2: clearline(vt, l, 0, vt->screen.ncol); break;
    }
}

static void sgr (TMT *vt) { TMTSCREEN *s = &vt->screen; TMTPOINT *c = &vt->curs; TMTLINE *l = (vt)->screen.lines[(((size_t)((vt)->curs.r) < (size_t)((vt)->screen.nline - 1)) ? (size_t)((vt)->curs.r) : (size_t)((vt)->screen.nline - 1))]; TMTCHAR *t = vt->tabs->chars;

    for (size_t i = 0; i < vt->npar; i++) switch ((vt->pars[i])){
        case 0: vt->attrs = defattrs; break;
        case 1: case 22: vt->attrs.bold = (vt->pars[0]) < 20; break;
        case 2: case 23: vt->attrs.dim = (vt->pars[0]) < 20; break;
        case 4: case 24: vt->attrs.underline = (vt->pars[0]) < 20; break;
        case 5: case 25: vt->attrs.blink = (vt->pars[0]) < 20; break;
        case 7: case 27: vt->attrs.reverse = (vt->pars[0]) < 20; break;
        case 8: case 28: vt->attrs.invisible = (vt->pars[0]) < 20; break;
        case 10: case 11: vt->acs = (vt->pars[0]) > 10; break;
        case 30: case 40: *((vt->pars[i]) < 40? &vt->attrs.fg : &vt->attrs.bg) = TMT_COLOR_BLACK; break;
        case 31: case 41: *((vt->pars[i]) < 40? &vt->attrs.fg : &vt->attrs.bg) = TMT_COLOR_RED; break;
        case 32: case 42: *((vt->pars[i]) < 40? &vt->attrs.fg : &vt->attrs.bg) = TMT_COLOR_GREEN; break;
        case 33: case 43: *((vt->pars[i]) < 40? &vt->attrs.fg : &vt->attrs.bg) = TMT_COLOR_YELLOW; break;
        case 34: case 44: *((vt->pars[i]) < 40? &vt->attrs.fg : &vt->attrs.bg) = TMT_COLOR_BLUE; break;
        case 35: case 45: *((vt->pars[i]) < 40? &vt->attrs.fg : &vt->attrs.bg) = TMT_COLOR_MAGENTA; break;
        case 36: case 46: *((vt->pars[i]) < 40? &vt->attrs.fg : &vt->attrs.bg) = TMT_COLOR_CYAN; break;
        case 37: case 47: *((vt->pars[i]) < 40? &vt->attrs.fg : &vt->attrs.bg) = TMT_COLOR_WHITE; break;
        case 39: case 49: *((vt->pars[i]) < 40? &vt->attrs.fg : &vt->attrs.bg) = TMT_COLOR_DEFAULT; break;
    }
}

static void rep (TMT *vt) { TMTSCREEN *s = &vt->screen; TMTPOINT *c = &vt->curs; TMTLINE *l = (vt)->screen.lines[(((size_t)((vt)->curs.r) < (size_t)((vt)->screen.nline - 1)) ? (size_t)((vt)->curs.r) : (size_t)((vt)->screen.nline - 1))]; TMTCHAR *t = vt->tabs->chars;
    if (!c->c) return;
    wchar_t r = l->chars[c->c - 1].c;
    for (size_t i = 0; i < (vt->pars[0]? vt->pars[0] : 1); i++)
        writecharatcurs(vt, r);
}

static void dsr (TMT *vt) { TMTSCREEN *s = &vt->screen; TMTPOINT *c = &vt->curs; TMTLINE *l = (vt)->screen.lines[(((size_t)((vt)->curs.r) < (size_t)((vt)->screen.nline - 1)) ? (size_t)((vt)->curs.r) : (size_t)((vt)->screen.nline - 1))]; TMTCHAR *t = vt->tabs->chars;
    char r[100 + 1] = {0};
    snprintf(r, 100, "\033[%zd;%zdR", c->r + 1, c->c + 1);
    ((vt)->cb? (vt)->cb(TMT_MSG_ANSWER, vt, (const char *)r, (vt)->p) : (void)0);
}

static void resetparser (TMT *vt) { TMTSCREEN *s = &vt->screen; TMTPOINT *c = &vt->curs; TMTLINE *l = (vt)->screen.lines[(((size_t)((vt)->curs.r) < (size_t)((vt)->screen.nline - 1)) ? (size_t)((vt)->curs.r) : (size_t)((vt)->screen.nline - 1))]; TMTCHAR *t = vt->tabs->chars;
    memset(vt->pars, 0, sizeof(vt->pars));
    vt->state = vt->npar = vt->arg = vt->ignored = (_Bool)0;
}

static void consumearg (TMT *vt) { TMTSCREEN *s = &vt->screen; TMTPOINT *c = &vt->curs; TMTLINE *l = (vt)->screen.lines[(((size_t)((vt)->curs.r) < (size_t)((vt)->screen.nline - 1)) ? (size_t)((vt)->curs.r) : (size_t)((vt)->screen.nline - 1))]; TMTCHAR *t = vt->tabs->chars;
    if (vt->npar < 8)
        vt->pars[vt->npar++] = vt->arg;
    vt->arg = 0;
}

static void fixcursor (TMT *vt) { TMTSCREEN *s = &vt->screen; TMTPOINT *c = &vt->curs; TMTLINE *l = (vt)->screen.lines[(((size_t)((vt)->curs.r) < (size_t)((vt)->screen.nline - 1)) ? (size_t)((vt)->curs.r) : (size_t)((vt)->screen.nline - 1))]; TMTCHAR *t = vt->tabs->chars;
    c->r = (((size_t)(c->r) < (size_t)(s->nline - 1)) ? (size_t)(c->r) : (size_t)(s->nline - 1));
    c->c = (((size_t)(c->c) < (size_t)(s->ncol - 1)) ? (size_t)(c->c) : (size_t)(s->ncol - 1));
}

static _Bool
handlechar(TMT *vt, char i)
{
    TMTSCREEN *s = &vt->screen; TMTPOINT *c = &vt->curs; TMTLINE *l = (vt)->screen.lines[(((size_t)((vt)->curs.r) < (size_t)((vt)->screen.nline - 1)) ? (size_t)((vt)->curs.r) : (size_t)((vt)->screen.nline - 1))]; TMTCHAR *t = vt->tabs->chars;

    char cs[] = {i, 0};




    if (vt->state == (S_NUL) && strchr("\x07", i)){ consumearg(vt); if (!vt->ignored) {((vt)->cb? (vt)->cb(TMT_MSG_BELL, vt, ((void*)0), (vt)->p) : (void)0);} fixcursor(vt); resetparser(vt);; return 1;};
    if (vt->state == (S_NUL) && strchr("\x08", i)){ consumearg(vt); if (!vt->ignored) {if (c->c) c->c--;} fixcursor(vt); resetparser(vt);; return 1;};
    if (vt->state == (S_NUL) && strchr("\x09", i)){ consumearg(vt); if (!vt->ignored) {while (++c->c < s->ncol - 1 && t[c->c].c != L'*');} fixcursor(vt); resetparser(vt);; return 1;};
    if (vt->state == (S_NUL) && strchr("\x0a", i)){ consumearg(vt); if (!vt->ignored) {c->r < s->nline - 1? (void)c->r++ : scrup(vt, 0, 1);} fixcursor(vt); resetparser(vt);; return 1;};
    if (vt->state == (S_NUL) && strchr("\x0d", i)){ consumearg(vt); if (!vt->ignored) {c->c = 0;} fixcursor(vt); resetparser(vt);; return 1;};
    if (vt->state == (S_NUL) && strchr("\x1b", i)){ vt->state = S_ESC; return 1;}
    if (vt->state == (S_ESC) && strchr("\x1b", i)){ vt->state = S_ESC; return 1;}
    if (vt->state == (S_ESC) && strchr("H", i)){ consumearg(vt); if (!vt->ignored) {t[c->c].c = L'*';} fixcursor(vt); resetparser(vt);; return 1;};
    if (vt->state == (S_ESC) && strchr("7", i)){ consumearg(vt); if (!vt->ignored) {vt->oldcurs = vt->curs; vt->oldattrs = vt->attrs;} fixcursor(vt); resetparser(vt);; return 1;};
    if (vt->state == (S_ESC) && strchr("8", i)){ consumearg(vt); if (!vt->ignored) {vt->curs = vt->oldcurs; vt->attrs = vt->oldattrs;} fixcursor(vt); resetparser(vt);; return 1;};
    if (vt->state == (S_ESC) && strchr("+*()", i)){ vt->ignored = 1; vt->state = S_ARG; return 1;}
    if (vt->state == (S_ESC) && strchr("c", i)){ consumearg(vt); if (!vt->ignored) {tmt_reset(vt);} fixcursor(vt); resetparser(vt);; return 1;};
    if (vt->state == (S_ESC) && strchr("[", i)){ vt->state = S_ARG; return 1;}
    if (vt->state == (S_ARG) && strchr("\x1b", i)){ vt->state = S_ESC; return 1;}
    if (vt->state == (S_ARG) && strchr(";", i)){ consumearg(vt); return 1;}
    if (vt->state == (S_ARG) && strchr("?", i)){ (void)0; return 1;}
    if (vt->state == (S_ARG) && strchr("0123456789", i)){ vt->arg = vt->arg * 10 + atoi(cs); return 1;}
    if (vt->state == (S_ARG) && strchr("A", i)){ consumearg(vt); if (!vt->ignored) {c->r = (((size_t)(c->r - (vt->pars[0]? vt->pars[0] : 1)) > (size_t)(0)) ? (size_t)(c->r - (vt->pars[0]? vt->pars[0] : 1)) : (size_t)(0));} fixcursor(vt); resetparser(vt);; return 1;};
    if (vt->state == (S_ARG) && strchr("B", i)){ consumearg(vt); if (!vt->ignored) {c->r = (((size_t)(c->r + (vt->pars[0]? vt->pars[0] : 1)) < (size_t)(s->nline - 1)) ? (size_t)(c->r + (vt->pars[0]? vt->pars[0] : 1)) : (size_t)(s->nline - 1));} fixcursor(vt); resetparser(vt);; return 1;};
    if (vt->state == (S_ARG) && strchr("C", i)){ consumearg(vt); if (!vt->ignored) {c->c = (((size_t)(c->c + (vt->pars[0]? vt->pars[0] : 1)) < (size_t)(s->ncol - 1)) ? (size_t)(c->c + (vt->pars[0]? vt->pars[0] : 1)) : (size_t)(s->ncol - 1));} fixcursor(vt); resetparser(vt);; return 1;};
    if (vt->state == (S_ARG) && strchr("D", i)){ consumearg(vt); if (!vt->ignored) {c->c = (((size_t)(c->c - (vt->pars[0]? vt->pars[0] : 1)) < (size_t)(c->c)) ? (size_t)(c->c - (vt->pars[0]? vt->pars[0] : 1)) : (size_t)(c->c));} fixcursor(vt); resetparser(vt);; return 1;};
    if (vt->state == (S_ARG) && strchr("E", i)){ consumearg(vt); if (!vt->ignored) {c->c = 0; c->r = (((size_t)(c->r + (vt->pars[0]? vt->pars[0] : 1)) < (size_t)(s->nline - 1)) ? (size_t)(c->r + (vt->pars[0]? vt->pars[0] : 1)) : (size_t)(s->nline - 1));} fixcursor(vt); resetparser(vt);; return 1;};
    if (vt->state == (S_ARG) && strchr("F", i)){ consumearg(vt); if (!vt->ignored) {c->c = 0; c->r = (((size_t)(c->r - (vt->pars[0]? vt->pars[0] : 1)) > (size_t)(0)) ? (size_t)(c->r - (vt->pars[0]? vt->pars[0] : 1)) : (size_t)(0));} fixcursor(vt); resetparser(vt);; return 1;};
    if (vt->state == (S_ARG) && strchr("G", i)){ consumearg(vt); if (!vt->ignored) {c->c = (((size_t)((vt->pars[0]? vt->pars[0] : 1) - 1) < (size_t)(s->ncol - 1)) ? (size_t)((vt->pars[0]? vt->pars[0] : 1) - 1) : (size_t)(s->ncol - 1));} fixcursor(vt); resetparser(vt);; return 1;};
    if (vt->state == (S_ARG) && strchr("d", i)){ consumearg(vt); if (!vt->ignored) {c->r = (((size_t)((vt->pars[0]? vt->pars[0] : 1) - 1) < (size_t)(s->nline - 1)) ? (size_t)((vt->pars[0]? vt->pars[0] : 1) - 1) : (size_t)(s->nline - 1));} fixcursor(vt); resetparser(vt);; return 1;};
    if (vt->state == (S_ARG) && strchr("Hf", i)){ consumearg(vt); if (!vt->ignored) {c->r = (vt->pars[0]? vt->pars[0] : 1) - 1; c->c = (vt->pars[1]? vt->pars[1] : 1) - 1;} fixcursor(vt); resetparser(vt);; return 1;};
    if (vt->state == (S_ARG) && strchr("I", i)){ consumearg(vt); if (!vt->ignored) {while (++c->c < s->ncol - 1 && t[c->c].c != L'*');} fixcursor(vt); resetparser(vt);; return 1;};
    if (vt->state == (S_ARG) && strchr("J", i)){ consumearg(vt); if (!vt->ignored) {ed(vt);} fixcursor(vt); resetparser(vt);; return 1;};
    if (vt->state == (S_ARG) && strchr("K", i)){ consumearg(vt); if (!vt->ignored) {el(vt);} fixcursor(vt); resetparser(vt);; return 1;};
    if (vt->state == (S_ARG) && strchr("L", i)){ consumearg(vt); if (!vt->ignored) {scrdn(vt, c->r, (vt->pars[0]? vt->pars[0] : 1));} fixcursor(vt); resetparser(vt);; return 1;};
    if (vt->state == (S_ARG) && strchr("M", i)){ consumearg(vt); if (!vt->ignored) {scrup(vt, c->r, (vt->pars[0]? vt->pars[0] : 1));} fixcursor(vt); resetparser(vt);; return 1;};
    if (vt->state == (S_ARG) && strchr("P", i)){ consumearg(vt); if (!vt->ignored) {dch(vt);} fixcursor(vt); resetparser(vt);; return 1;};
    if (vt->state == (S_ARG) && strchr("S", i)){ consumearg(vt); if (!vt->ignored) {scrup(vt, 0, (vt->pars[0]? vt->pars[0] : 1));} fixcursor(vt); resetparser(vt);; return 1;};
    if (vt->state == (S_ARG) && strchr("T", i)){ consumearg(vt); if (!vt->ignored) {scrdn(vt, 0, (vt->pars[0]? vt->pars[0] : 1));} fixcursor(vt); resetparser(vt);; return 1;};
    if (vt->state == (S_ARG) && strchr("X", i)){ consumearg(vt); if (!vt->ignored) {clearline(vt, l, c->c, (vt->pars[0]? vt->pars[0] : 1));} fixcursor(vt); resetparser(vt);; return 1;};
    if (vt->state == (S_ARG) && strchr("Z", i)){ consumearg(vt); if (!vt->ignored) {while (c->c && t[--c->c].c != L'*');} fixcursor(vt); resetparser(vt);; return 1;};
    if (vt->state == (S_ARG) && strchr("b", i)){ consumearg(vt); if (!vt->ignored) {rep(vt);} fixcursor(vt); resetparser(vt);; return 1;};;
    if (vt->state == (S_ARG) && strchr("c", i)){ consumearg(vt); if (!vt->ignored) {((vt)->cb? (vt)->cb(TMT_MSG_ANSWER, vt, "\033[?6c", (vt)->p) : (void)0);} fixcursor(vt); resetparser(vt);; return 1;};
    if (vt->state == (S_ARG) && strchr("g", i)){ consumearg(vt); if (!vt->ignored) {if ((vt->pars[0]) == 3) clearline(vt, vt->tabs, 0, s->ncol);} fixcursor(vt); resetparser(vt);; return 1;};
    if (vt->state == (S_ARG) && strchr("m", i)){ consumearg(vt); if (!vt->ignored) {sgr(vt);} fixcursor(vt); resetparser(vt);; return 1;};
    if (vt->state == (S_ARG) && strchr("n", i)){ consumearg(vt); if (!vt->ignored) {if ((vt->pars[0]) == 6) dsr(vt);} fixcursor(vt); resetparser(vt);; return 1;};
    if (vt->state == (S_ARG) && strchr("h", i)){ consumearg(vt); if (!vt->ignored) {if ((vt->pars[0]) == 25) ((vt)->cb? (vt)->cb(TMT_MSG_CURSOR, vt, "t", (vt)->p) : (void)0);} fixcursor(vt); resetparser(vt);; return 1;};
    if (vt->state == (S_ARG) && strchr("i", i)){ consumearg(vt); if (!vt->ignored) {(void)0;} fixcursor(vt); resetparser(vt);; return 1;};
    if (vt->state == (S_ARG) && strchr("l", i)){ consumearg(vt); if (!vt->ignored) {if ((vt->pars[0]) == 25) ((vt)->cb? (vt)->cb(TMT_MSG_CURSOR, vt, "f", (vt)->p) : (void)0);} fixcursor(vt); resetparser(vt);; return 1;};
    if (vt->state == (S_ARG) && strchr("s", i)){ consumearg(vt); if (!vt->ignored) {vt->oldcurs = vt->curs; vt->oldattrs = vt->attrs;} fixcursor(vt); resetparser(vt);; return 1;};
    if (vt->state == (S_ARG) && strchr("u", i)){ consumearg(vt); if (!vt->ignored) {vt->curs = vt->oldcurs; vt->attrs = vt->oldattrs;} fixcursor(vt); resetparser(vt);; return 1;};
    if (vt->state == (S_ARG) && strchr("@", i)){ consumearg(vt); if (!vt->ignored) {ich(vt);} fixcursor(vt); resetparser(vt);; return 1;};

    return resetparser(vt), 0;
}

static void
notify(TMT *vt, _Bool update, _Bool moved)
{
    if (update) ((vt)->cb? (vt)->cb(TMT_MSG_UPDATE, vt, &vt->screen, (vt)->p) : (void)0);
    if (moved) ((vt)->cb? (vt)->cb(TMT_MSG_MOVED, vt, &vt->curs, (vt)->p) : (void)0);
}

static TMTLINE *
allocline(TMT *vt, TMTLINE *o, size_t n, size_t pc)
{
    TMTLINE *l = realloc(o, sizeof(TMTLINE) + n * sizeof(TMTCHAR));
    if (!l) return ((void*)0);

    clearline(vt, l, pc, n);
    return l;
}

static void
freelines(TMT *vt, size_t s, size_t n, _Bool screen)
{
    for (size_t i = s; vt->screen.lines && i < s + n; i++){
        free(vt->screen.lines[i]);
        vt->screen.lines[i] = ((void*)0);
    }
    if (screen) free(vt->screen.lines);
}

TMT *
tmt_open(size_t nline, size_t ncol, TMTCALLBACK cb, void *p,
         const wchar_t *acs)
{
    TMT *vt = calloc(1, sizeof(TMT));
    if (!nline || !ncol || !vt) return free(vt), ((void*)0);


    vt->acschars = acs? acs : L"><^v#+:o##+++++~---_++++|<>*!fo";
    vt->cb = cb;
    vt->p = p;

    if (!tmt_resize(vt, nline, ncol)) return tmt_close(vt), ((void*)0);
    return vt;
}

void
tmt_close(TMT *vt)
{
    free(vt->tabs);
    freelines(vt, 0, vt->screen.nline, 1);
    free(vt);
}

_Bool
tmt_resize(TMT *vt, size_t nline, size_t ncol)
{
    if (nline < 2 || ncol < 2) return 0;
    if (nline < vt->screen.nline)
        freelines(vt, nline, vt->screen.nline - nline, 0);

    TMTLINE **l = realloc(vt->screen.lines, nline * sizeof(TMTLINE *));
    if (!l) return 0;

    size_t pc = vt->screen.ncol;
    vt->screen.lines = l;
    vt->screen.ncol = ncol;
    for (size_t i = 0; i < nline; i++){
        TMTLINE *nl = ((void*)0);
        if (i >= vt->screen.nline)
            nl = vt->screen.lines[i] = allocline(vt, ((void*)0), ncol, 0);
        else
            nl = allocline(vt, vt->screen.lines[i], ncol, pc);

        if (!nl) return 0;
        vt->screen.lines[i] = nl;
    }
    vt->screen.nline = nline;

    vt->tabs = allocline(vt, vt->tabs, ncol, 0);
    if (!vt->tabs) return free(l), 0;
    vt->tabs->chars[0].c = vt->tabs->chars[ncol - 1].c = L'*';
    for (size_t i = 0; i < ncol; i++) if (i % 8 == 0)
        vt->tabs->chars[i].c = L'*';

    fixcursor(vt);
    dirtylines(vt, 0, nline);
    notify(vt, 1, 1);
    return 1;
}

static void
writecharatcurs(TMT *vt, wchar_t w)
{
    TMTSCREEN *s = &vt->screen; TMTPOINT *c = &vt->curs; TMTLINE *l = (vt)->screen.lines[(((size_t)((vt)->curs.r) < (size_t)((vt)->screen.nline - 1)) ? (size_t)((vt)->curs.r) : (size_t)((vt)->screen.nline - 1))]; TMTCHAR *t = vt->tabs->chars;







    (vt)->screen.lines[(((size_t)((vt)->curs.r) < (size_t)((vt)->screen.nline - 1)) ? (size_t)((vt)->curs.r) : (size_t)((vt)->screen.nline - 1))]->chars[vt->curs.c].c = w;
    (vt)->screen.lines[(((size_t)((vt)->curs.r) < (size_t)((vt)->screen.nline - 1)) ? (size_t)((vt)->curs.r) : (size_t)((vt)->screen.nline - 1))]->chars[vt->curs.c].a = vt->attrs;
    (vt)->screen.lines[(((size_t)((vt)->curs.r) < (size_t)((vt)->screen.nline - 1)) ? (size_t)((vt)->curs.r) : (size_t)((vt)->screen.nline - 1))]->dirty = vt->dirty = 1;

    if (c->c < s->ncol - 1)
        c->c++;
    else{
        c->c = 0;
        c->r++;
    }

    if (c->r >= s->nline){
        c->r = s->nline - 1;
        scrup(vt, 0, 1);
    }
}

static inline size_t
testmbchar(TMT *vt)
{
    mbstate_t ts = vt->ms;
    return vt->nmb? mbrtowc(((void*)0), vt->mb, vt->nmb, &ts) : (size_t)-2;
}

static inline wchar_t
getmbchar(TMT *vt)
{
    wchar_t c = 0;
    size_t n = mbrtowc(&c, vt->mb, vt->nmb, &vt->ms);
    vt->nmb = 0;
    return (n == (size_t)-1 || n == (size_t)-2)? ((wchar_t)0xfffd) : c;
}

void
tmt_write(TMT *vt, const char *s, size_t n)
{
    TMTPOINT oc = vt->curs;
    n = n? n : strlen(s);

    for (size_t p = 0; p < n; p++){
        if (handlechar(vt, s[p]))
            continue;
        else if (vt->acs)
            writecharatcurs(vt, tacs(vt, (unsigned char)s[p]));
        else if (vt->nmb >= 100)
            writecharatcurs(vt, getmbchar(vt));
        else{
            switch (testmbchar(vt)){
                case (size_t)-1: writecharatcurs(vt, getmbchar(vt)); break;
                case (size_t)-2: vt->mb[vt->nmb++] = s[p]; break;
            }

            if (testmbchar(vt) <= 16)
                writecharatcurs(vt, getmbchar(vt));
        }
    }

    notify(vt, vt->dirty, memcmp(&oc, &vt->curs, sizeof(oc)) != 0);
}

const TMTSCREEN *
tmt_screen(const TMT *vt)
{
    return &vt->screen;
}

const TMTPOINT *
tmt_cursor(const TMT *vt)
{
    return &vt->curs;
}

void
tmt_clean(TMT *vt)
{
    for (size_t i = 0; i < vt->screen.nline; i++)
        vt->dirty = vt->screen.lines[i]->dirty = 0;
}

void
tmt_reset(TMT *vt)
{
    vt->curs.r = vt->curs.c = vt->oldcurs.r = vt->oldcurs.c = vt->acs = (_Bool)0;
    resetparser(vt);
    vt->attrs = vt->oldattrs = defattrs;
    memset(&vt->ms, 0, sizeof(vt->ms));
    clearlines(vt, 0, vt->screen.nline);
    ((vt)->cb? (vt)->cb(TMT_MSG_CURSOR, vt, "t", (vt)->p) : (void)0);
    notify(vt, 1, 1);
}
