#ifndef __AF_BLENDER_HEADER
#define __AF_BLENDER_HEADER

namespace allegro_flare {


enum blender_t
{
   BLENDER_UNDEF,
   BLENDER_NORMAL,
   BLENDER_ADDITIVE,
   BLENDER_MULTIPLY,
   BLENDER_SUBTRACTIVE,
   BLENDER_SCREEN
};




void set_blender(blender_t type);


}

#endif
