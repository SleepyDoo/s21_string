#ifndef SRC_S21_STRING_H_
#define SRC_S21_STRING_H_
#define s21_size_t unsigned long long
#define s21_NULL (void *)0

typedef struct mod {
  int flag;
  int width;
  char precision[40];
  char length[10];
  int length_s;
} mod;

typedef struct flags {
  int format_f;
  int sign;
  int width;
  int precision;
  int set_precision;
  int align;
  int length;
  int dot;
  int double_length;
  int spec;
  int if_num;
  int zero_width;
} flags;

#define AMOUNT_ERROR_MAC 106
#define AMOUNT_ERROR_LINUX 133
#if __APPLE__
#define AMOUNT_ERROR AMOUNT_ERROR_MAC
#elif __linux__
#define AMOUNT_ERROR AMOUNT_ERROR_LINUX
#endif

#if __APPLE__
#define ERROR_ARRAY                                                 \
  char *errorstr[AMOUNT_ERROR_MAC + 1];                             \
  errorstr[0] = "Undefined error: 0";                               \
  errorstr[1] = "Operation not permitted";                          \
  errorstr[3] = "No such process";                                  \
  errorstr[7] = "Argument list too long";                           \
  errorstr[8] = "Exec format error";                                \
  errorstr[9] = "Bad file descriptor";                              \
  errorstr[10] = "No child processes";                              \
  errorstr[11] = "Resource deadlock avoided";                       \
  errorstr[12] = "Cannot allocate memory";                          \
  errorstr[13] = "Permission denied";                               \
  errorstr[14] = "Bad address";                                     \
  errorstr[15] = "Block device required";                           \
  errorstr[16] = "Resource busy";                                   \
  errorstr[17] = "File exists";                                     \
  errorstr[18] = "Cross-device link";                               \
  errorstr[19] = "Operation not supported by device";               \
  errorstr[20] = "Not a directory";                                 \
  errorstr[21] = "Is a directory";                                  \
  errorstr[22] = "Invalid argument";                                \
  errorstr[23] = "Too many open files in system";                   \
  errorstr[24] = "Too many open files";                             \
  errorstr[25] = "Inappropriate ioctl for device";                  \
  errorstr[26] = "Text file busy";                                  \
  errorstr[27] = "File too large";                                  \
  errorstr[28] = "No space left on device";                         \
  errorstr[29] = "Illegal seek";                                    \
  errorstr[30] = "Read-only file system";                           \
  errorstr[31] = "Too many links";                                  \
  errorstr[32] = "Broken pipe";                                     \
  errorstr[33] = "Numerical argument out of domain";                \
  errorstr[34] = "Result too large";                                \
  errorstr[35] = "Resource temporarily unavailable";                \
  errorstr[36] = "Operation now in progress";                       \
  errorstr[37] = "Operation already in progress";                   \
  errorstr[38] = "Socket operation on non-socket";                  \
  errorstr[39] = "Destination address required";                    \
  errorstr[40] = "Message too long";                                \
  errorstr[41] = "Protocol wrong type for socket";                  \
  errorstr[42] = "Protocol not available";                          \
  errorstr[43] = "Protocol not supported";                          \
  errorstr[44] = "Socket type not supported";                       \
  errorstr[45] = "Operation not supported";                         \
  errorstr[46] = "Protocol family not supported";                   \
  errorstr[47] = "Address family not supported by protocol family"; \
  errorstr[48] = "Address already in use";                          \
  errorstr[49] = "Can’t assign requested address";                  \
  errorstr[50] = "Network is down";                                 \
  errorstr[51] = "Network is unreachable";                          \
  errorstr[52] = "Network dropped connection on reset";             \
  errorstr[53] = "Software caused connection abort";                \
  errorstr[54] = "Connection reset by peer";                        \
  errorstr[55] = "No buffer space available";                       \
  errorstr[56] = "Socket is already connected";                     \
  errorstr[57] = "Socket is not connected";                         \
  errorstr[58] = "Can’t send after socket shutdown";                \
  errorstr[59] = "Too many references: can’t splice";               \
  errorstr[60] = "Operation timed out";                             \
  errorstr[61] = "Connection refused";                              \
  errorstr[62] = "Too many levels of symbolic links";               \
  errorstr[63] = "File name too long";                              \
  errorstr[64] = "Host is down";                                    \
  errorstr[65] = "No route to host";                                \
  errorstr[66] = "Directory not empty";                             \
  errorstr[67] = "Too many processes";                              \
  errorstr[68] = "Too many users";                                  \
  errorstr[69] = "Disc quota exceeded";                             \
  errorstr[70] = "Stale NFS file handle";                           \
  errorstr[71] = "Too many levels of remote in path";               \
  errorstr[72] = "RPC struct is bad";                               \
  errorstr[73] = "RPC version wrong";                               \
  errorstr[74] = "RPC prog. not avail";                             \
  errorstr[75] = "Program version wrong";                           \
  errorstr[76] = "Bad procedure for program";                       \
  errorstr[77] = "No locks available";                              \
  errorstr[78] = "Function not implemented";                        \
  errorstr[79] = "Inappropriate file type or format";               \
  errorstr[80] = "Authentication error";                            \
  errorstr[81] = "Need authenticator";                              \
  errorstr[82] = "Device power is off";                             \
  errorstr[83] = "Device error";                                    \
  errorstr[84] = "Value too large to be stored in data type";       \
  errorstr[85] = "Bad executable (or shared library)";              \
  errorstr[86] = "Bad CPU type in executable";                      \
  errorstr[87] = "Shared library version mismatch";                 \
  errorstr[88] = "Malformed Mach-o file";                           \
  errorstr[89] = "Operation canceled";                              \
  errorstr[90] = "Identifier removed";                              \
  errorstr[91] = "No message of desired type";                      \
  errorstr[92] = "Illegal byte sequence";                           \
  errorstr[93] = "Attribute not found";                             \
  errorstr[94] = "Bad message";                                     \
  errorstr[95] = "EMULTIHOP (Reserved)";                            \
  errorstr[96] = "No message available on STREAM";                  \
  errorstr[97] = "ENOLINK (Reserved)";                              \
  errorstr[98] = "No STREAM resources";                             \
  errorstr[99] = "Not a STREAM";                                    \
  errorstr[100] = "Protocol error";                                 \
  errorstr[101] = "STREAM ioctl timeout";                           \
  errorstr[102] = "Operation not supported on socket";              \
  errorstr[103] = "Policy not found";                               \
  errorstr[104] = "State not recoverable";                          \
  errorstr[105] = "Previous owner died";                            \
  errorstr[106] = "Interface output queue is full";
#endif
#if __linux__
#define ERROR_ARRAY                                                   \
  char *errorstr[AMOUNT_ERROR_LINUX + 1];                             \
  errorstr[0] = "Success";                                            \
  errorstr[1] = "Operation not permitted";                            \
  errorstr[2] = "No such file or directory";                          \
  errorstr[3] = "No such process";                                    \
  errorstr[4] = "Interrupted system call";                            \
  errorstr[5] = "Input/output error";                                 \
  errorstr[6] = "No such device or address";                          \
  errorstr[7] = "Argument list too long";                             \
  errorstr[8] = "Exec format error";                                  \
  errorstr[9] = "Bad file descriptor";                                \
  errorstr[10] = "No child processes";                                \
  errorstr[11] = "Resource temporarily unavailable";                  \
  errorstr[12] = "Cannot allocate memory";                            \
  errorstr[13] = "Permission denied";                                 \
  errorstr[14] = "Bad address";                                       \
  errorstr[15] = "Block device required";                             \
  errorstr[16] = "Device or resource busy";                           \
  errorstr[17] = "File exists";                                       \
  errorstr[18] = "Invalid cross-device link";                         \
  errorstr[19] = "No such device";                                    \
  errorstr[20] = "Not a directory";                                   \
  errorstr[21] = "Is a directory";                                    \
  errorstr[22] = "Invalid argument";                                  \
  errorstr[23] = "Too many open files in system";                     \
  errorstr[24] = "Too many open files";                               \
  errorstr[25] = "Inappropriate ioctl for device";                    \
  errorstr[26] = "Text file busy";                                    \
  errorstr[27] = "File too large";                                    \
  errorstr[28] = "No space left on device";                           \
  errorstr[29] = "Illegal seek";                                      \
  errorstr[30] = "Read-only file system";                             \
  errorstr[31] = "Too many links";                                    \
  errorstr[32] = "Broken pipe";                                       \
  errorstr[33] = "Numerical argument out of domain";                  \
  errorstr[34] = "Numerical result out of range";                     \
  errorstr[35] = "Resource deadlock avoided";                         \
  errorstr[36] = "File name too long";                                \
  errorstr[37] = "No locks available";                                \
  errorstr[38] = "Function not implemented";                          \
  errorstr[39] = "Directory not empty";                               \
  errorstr[40] = "Too many levels of symbolic links";                 \
  errorstr[41] = "Unknown error 41";                                  \
  errorstr[42] = "No message of desired type";                        \
  errorstr[43] = "Identifier removed";                                \
  errorstr[44] = "Channel number out of range";                       \
  errorstr[45] = "Level 2 not synchronized";                          \
  errorstr[46] = "Level 3 halted";                                    \
  errorstr[47] = "Level 3 reset";                                     \
  errorstr[48] = "Link number out of range";                          \
  errorstr[49] = "Protocol driver not attached";                      \
  errorstr[50] = "No CSI structure available";                        \
  errorstr[51] = "Level 2 halted";                                    \
  errorstr[52] = "Invalid exchange";                                  \
  errorstr[53] = "Invalid request descriptor";                        \
  errorstr[54] = "Exchange full";                                     \
  errorstr[55] = "No anode";                                          \
  errorstr[56] = "Invalid request code";                              \
  errorstr[57] = "Invalid slot";                                      \
  errorstr[58] = "Unknown error 58";                                  \
  errorstr[59] = "Bad font file format";                              \
  errorstr[60] = "Device not a stream";                               \
  errorstr[61] = "No data available";                                 \
  errorstr[62] = "Timer expired";                                     \
  errorstr[63] = "Out of streams resources";                          \
  errorstr[64] = "Machine is not on the network";                     \
  errorstr[65] = "Package not installed";                             \
  errorstr[66] = "Object is remote";                                  \
  errorstr[67] = "Link has been severed";                             \
  errorstr[68] = "Advertise error";                                   \
  errorstr[69] = "Srmount error";                                     \
  errorstr[70] = "Communication error on send";                       \
  errorstr[71] = "Protocol error";                                    \
  errorstr[72] = "Multihop attempted";                                \
  errorstr[73] = "RFS specific error";                                \
  errorstr[74] = "Bad message";                                       \
  errorstr[75] = "Value too large for defined data type";             \
  errorstr[76] = "Name not unique on network";                        \
  errorstr[77] = "File descriptor in bad state";                      \
  errorstr[78] = "Remote address changed";                            \
  errorstr[79] = "Can not access a needed shared library";            \
  errorstr[80] = "Accessing a corrupted shared library";              \
  errorstr[81] = ".lib section in a.out corrupted";                   \
  errorstr[82] = "Attempting to link in too many shared libraries";   \
  errorstr[83] = "Cannot exec a shared library directly";             \
  errorstr[84] = "Invalid or incomplete multibyte or wide character"; \
  errorstr[85] = "Interrupted system call should be restarted";       \
  errorstr[86] = "Streams pipe error";                                \
  errorstr[87] = "Too many users";                                    \
  errorstr[88] = "Socket operation on non-socket";                    \
  errorstr[89] = "Destination address required";                      \
  errorstr[90] = "Message too long";                                  \
  errorstr[91] = "Protocol wrong type for socket";                    \
  errorstr[92] = "Protocol not available";                            \
  errorstr[93] = "Protocol not supported";                            \
  errorstr[94] = "Socket type not supported";                         \
  errorstr[95] = "Operation not supported";                           \
  errorstr[96] = "Protocol family not supported";                     \
  errorstr[97] = "Address family not supported by protocol";          \
  errorstr[98] = "Address already in use";                            \
  errorstr[99] = "Cannot assign requested address";                   \
  errorstr[100] = "Network is down";                                  \
  errorstr[101] = "Network is unreachable";                           \
  errorstr[102] = "Network dropped connection on reset";              \
  errorstr[103] = "Software caused connection abort";                 \
  errorstr[104] = "Connection reset by peer";                         \
  errorstr[105] = "No buffer space available";                        \
  errorstr[106] = "Transport endpoint is already connected";          \
  errorstr[107] = "Transport endpoint is not connected";              \
  errorstr[108] = "Cannot send after transport endpoint shutdown";    \
  errorstr[109] = "Too many references: cannot splice";               \
  errorstr[110] = "Connection timed out";                             \
  errorstr[111] = "Connection refused";                               \
  errorstr[112] = "Host is down";                                     \
  errorstr[113] = "No route to host";                                 \
  errorstr[114] = "Operation already in progress";                    \
  errorstr[115] = "Operation now in progress";                        \
  errorstr[116] = "Stale file handle";                                \
  errorstr[117] = "Structure needs cleaning";                         \
  errorstr[118] = "Not a XENIX named type file";                      \
  errorstr[119] = "No XENIX semaphores available";                    \
  errorstr[120] = "Is a named type file";                             \
  errorstr[121] = "Remote I/O error";                                 \
  errorstr[122] = "Disk quota exceeded";                              \
  errorstr[123] = "No medium found";                                  \
  errorstr[124] = "Wrong medium type";                                \
  errorstr[125] = "Operation canceled";                               \
  errorstr[126] = "Required key not available";                       \
  errorstr[127] = "Key has expired";                                  \
  errorstr[128] = "Key has been revoked";                             \
  errorstr[129] = "Key was rejected by service";                      \
  errorstr[130] = "Owner died";                                       \
  errorstr[131] = "State not recoverable";                            \
  errorstr[132] = "Operation not possible due to RF-kill";            \
  errorstr[133] = "Memory page has hardware error";
#endif

int s21_memcmp(const void *string1, const void *string2, s21_size_t num);
int s21_strcmp(const char *string1, const char *string2);
int s21_strncmp(const char *string1, const char *string2, s21_size_t num);
char *s21_strchr(const char *str, int c);
char *s21_strcpy(char *dest, const char *src);
char *s21_strcat(char *str1, char *str2);
char *s21_strncat(char *str1, char *str2, s21_size_t n);
char *s21_strtok(char *str, const char *delim);
char *s21_strerror(int errnum);
void *s21_memchr(const void *str, int c, s21_size_t n);
char *s21_strchr(const char *str, int c);
char *s21_strrchr(const char *str, int c);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strstr(const char *haystack, const char *needle);
int s21_sscanf(const char *str, const char *format, ...);
s21_size_t s21_strlen(const char *str);
s21_size_t s21_strspn(const char *str1, const char *str2);
s21_size_t s21_strcspn(const char *str1, const char *str2);
int s21_sprintf(char *str, const char *format, ...);
char *s21_strcpy(char *dest, const char *src);
s21_size_t s21_strlen(const char *str);
void *s21_memcpy(void *dest, const void *src, s21_size_t n);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
void *s21_memmove(void *dest, const void *src, s21_size_t n);
void *s21_memset(void *str, int c, s21_size_t n);
void *s21_to_upper(const char *start);
void *s21_to_lower(const char *start);
void *s21_insert(const char *src, const char *str, s21_size_t start_index);
void *s21_trim(const char *src, const char *trim_chars);

#endif  // SRC_S21_STRING_H_
