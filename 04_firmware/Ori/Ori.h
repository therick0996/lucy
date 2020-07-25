
#pragma once

#include "quantum.h"

#define ____ KC_NO


// This a shortcut to help you visually see your layout.
// The first section contains all of the arguments
// The second converts the arguments into a two-dimensional array

#define LAYOUT_ortho_1x4x12x1( \
    k001,   k002, k003, k004, k005, k006, k007, k008, k009, k010, k011, k012, k013,   k014, \
    k101,   k102, k103, k104, k105, k106, k107, k108, k109, k110, k111, k112, k113,   k114, \
    k201,   k202, k203, k204, k205, k206, k207, k208, k209, k210, k211, k212, k213,   k214, \
    k301,   k302, k303, k304, k305, k306, k307, k308, k309, k310, k311, k312, k313,   k314  \
) \
{ \
    { k001,    k002, k003, k004, k005, k006, k007, k008, k009, k010, k011, k012, k013,    k014 }, \
    { k101,    k102, k103, k104, k105, k106, k107, k108, k109, k110, k111, k112, k113,    k114 }, \
    { k201,    k202, k203, k204, k205, k206, k207, k208, k209, k210, k211, k212, k213,    k214 }, \
    { k301,    k302, k303, k304, k305, k306, k307, k308, k309, k310, k311, k312, k313,    k314 }  \
}

#define LAYOUT_ortho_1x4x12( \
    k001,   k002, k003, k004, k005, k006, k007, k008, k009, k010, k011, k012, k013, \
    k101,   k102, k103, k104, k105, k106, k107, k108, k109, k110, k111, k112, k113, \
    k201,   k202, k203, k204, k205, k206, k207, k208, k209, k210, k211, k212, k213, \
    k301,   k302, k303, k304, k305, k306, k307, k308, k309, k310, k311, k312, k313  \
) \
{ \
    { k001,    k002, k003, k004, k005, k006, k007, k008, k009, k010, k011, k012, k013,    ____ }, \
    { k101,    k102, k103, k104, k105, k106, k107, k108, k109, k110, k111, k112, k113,    ____ }, \
    { k201,    k202, k203, k204, k205, k206, k207, k208, k209, k210, k211, k212, k213,    ____ }, \
    { k301,    k302, k303, k304, k305, k306, k307, k308, k309, k310, k311, k312, k313,    ____ }  \
}

#define LAYOUT_ortho_4x12x1( \
    k002, k030, k004, k005, k006, k007, k008, k009, k010, k011, k012, k013,   k014, \
    k102, k103, k104, k105, k106, k107, k108, k109, k110, k111, k112, k113,   k114, \
    k202, k203, k204, k205, k206, k207, k208, k209, k210, k211, k212, k213,   k214, \
    k302, k303, k304, k305, k306, k307, k308, k309, k310, k311, k312, k313,   k314  \
) \
{ \
    { ____,    k002, k003, k004, k005, k006, k007, k008, k009, k010, k011, k012, k013,    k014 }, \
    { ____,    k102, k103, k104, k105, k106, k107, k108, k109, k110, k111, k112, k113,    k114 }, \
    { ____,    k202, k203, k204, k205, k206, k207, k208, k209, k210, k211, k212, k213,    k214 }, \
    { ____,    k302, k303, k304, k305, k306, k307, k308, k309, k310, k311, k312, K313,    k314 }  \
}

#define LAYOUT_ortho_4x12( \
    k002, k003, k004, k005, k006, k007, k008, k009, k010, k011, k012, k013, \
    k102, k103, k104, k105, k106, k107, k108, k109, k110, k111, k112, k113, \
    k202, k203, k204, k205, k206, k207, k208, k209, k210, k211, k212, k213, \
    k302, k303, k304, k305, k306, k307, k308, k309, k310, k311, k312, k313  \
) \
{ \
    { ____,    k002, k003, k004, k005, k006, k007, k008, k009, k010, k011, k012, k013,    ____ }, \
    { ____,    k102, k103, k104, k105, k106, k107, k108, k109, k110, k111, k112, k113,    ____ }, \
    { ____,    k202, k203, k204, k205, k206, k207, k208, k209, k210, k211, k212, k213,    ____ }, \
    { ____,    k302, k303, k304, k305, k306, k307, k308, k309, k310, k311, k312, k313,    ____ }  \
}
