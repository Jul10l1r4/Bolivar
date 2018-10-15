#ifndef MINITYPES_H
#define MINITYPES_H

char *default_mime_type = "text/plain";

typedef struct {
    const char *extension;
    const char *mime_type;
} mime_map;

/* 
 *  Add new value in list:
 *  {"extension","mine-type"},
 */
mime_map meme_types [] = {
    {".css", "text/css"},
    {".gif", "image/gif"},
    {".htm", "text/html"},
    {".html", "text/html"},
    {".jpeg", "image/jpeg"},
    {".jpg", "image/jpeg"},
    {".ico", "image/x-icon"},
    {".js", "application/javascript"},
    {".pdf", "application/pdf"},
    {".mp4", "video/mp4"},
    {".webm","video/webm"},
    {".png", "image/png"},
    {".svg", "image/svg+xml"},
    {".xml", "text/xml"},
    {NULL, NULL},
};

#endif