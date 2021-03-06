



#include <allegro_flare/row.h>




namespace allegro_flare
{
   UISurfaceAreaRow::UISurfaceAreaRow(float y, float h)
      : UISurfaceAreaBase(0, y, 1, h)
   {
      placement.align = AllegroFlare::vec2d(0, 0);
   }




   void UISurfaceAreaRow::draw_bounding_area()
   {
   }




   bool UISurfaceAreaRow::collides(float x, float y)
   {
      placement.transform_coordinates(&x, &y);
      if (y < placement.position.y) return false;
      if (y > placement.position.y + placement.size.y) return false;
      return true;
   }
}



