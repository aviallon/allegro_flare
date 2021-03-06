



#include <iostream>
#include <allegro_flare/box_padded.h>
#include <AllegroFlare/Color.hpp>




namespace allegro_flare
{
   UISurfaceAreaBoxPadded::UISurfaceAreaBoxPadded(float x, float y, float w, float h, float pt, float pr, float pb, float pl)
      : UISurfaceAreaBase(x, y, w, h)
      , padding_top(pt)
      , padding_right(pr)
      , padding_bottom(pb)
      , padding_left(pl)
   {
   }




   UISurfaceAreaBoxPadded::~UISurfaceAreaBoxPadded()
   {
   }




   bool UISurfaceAreaBoxPadded::collides(float x, float y)
   {
      return placement.collide(x, y, padding_top, padding_right, padding_bottom, padding_left);
   }




   void UISurfaceAreaBoxPadded::draw_bounding_area()
   {
      placement.draw_box_with_padding(AllegroFlare::color::color(AllegroFlare::color::aliceblue, 0.2), true,
            padding_top, padding_right, padding_bottom, padding_left);
   }




   void UISurfaceAreaBoxPadded::get_padding(float *pt, float *pr, float *pb, float *pl)
   {
      *pt = padding_top;
      *pr = padding_right;
      *pb = padding_bottom;
      *pl = padding_left;
   }




   void UISurfaceAreaBoxPadded::set_padding(float pt, float pr, float pb, float pl)
   {
      padding_top = pt;
      padding_right = pr;
      padding_bottom = pb;
      padding_left = pl;
   }
}




