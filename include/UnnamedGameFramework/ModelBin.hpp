#pragma once


#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <UnnamedGameFramework/Bin.hpp>
#include <UnnamedGameFramework/Model3D.hpp>


class ModelBin : public Bin<std::string, Model3D *>
{
public:
   ModelBin();
   ~ModelBin();
   Model3D *load_data(std::string identifier);
   void destroy_data(Model3D *bmp);
};


