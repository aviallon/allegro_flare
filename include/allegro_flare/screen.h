#ifndef __AF_SCREEN_HEADER
#define __AF_SCREEN_HEADER




#include <string>
#include <vector>
#include <allegro5/allegro.h>
#include <allegro_flare/display.h>


namespace allegro_flare {

    class Screen
    {
    private:
       friend class Framework;
       friend class Display;

       static std::vector<Screen *> screens; // this was recently changed from "instance" to "screens"
       static void on_events(ALLEGRO_EVENT *ev);
       static void primary_timer_funcs();  // WARNING! this USED to be timer_funcs() in 0.7 and prior.
       static void timer_funcs(); // WARNING! this used to be timer2_funcs() and was changed to timer_funcs() in 0.8, older versions will need to be changed
       static void display_switch_in_funcs();
       static void display_switch_out_funcs();
       static void key_down_funcs();
       static void key_up_funcs();
       static void mouse_axes_funcs();
       static void mouse_warp_funcs();
       static void mouse_down_funcs();
       static void mouse_up_funcs();
       static void key_char_funcs();
       static void joy_button_down_funcs();
       static void joy_button_up_funcs();
       static void joy_axis_funcs();
       static void joy_config_funcs();
       static void user_event_funcs();
       static void native_menu_click_funcs();

    private:
       void prepare_drawing_state(bool prepare_3d=false);

    public:
       ALLEGRO_BITMAP *backbuffer_sub_bitmap;
       Display *display;

       void create_and_use_backbuffer_sub_bitmap_of(ALLEGRO_BITMAP *new_target);

       static void send_signal(int signal, void *data); // experimental
       static void send_signal(std::string const &signal, void *data); // I'm likin it
       // TODO!! signal should no longer be a reference, just a const std::string
       static bool signal_has_header(std::string header, std::string signal);
       static std::string strip_signal_header(std::string header, std::string signal);

       virtual void on_event(ALLEGRO_EVENT *ev);

       virtual void primary_timer_func();  // WARNING! this USED to be timer_func() in 0.7 and prior.  primary_timer_func() should now be used where timer_func() was used durin 0.7 programs
       virtual void timer_func(); // WARNING! this used to be timer2_func() and was changed to timer_func() in 0.8, older versions will need to be changed
       virtual void display_switch_in_func();
       virtual void display_switch_out_func();
       virtual void mouse_axes_func();
       virtual void mouse_warp_func();
       virtual void mouse_down_func();
       virtual void mouse_up_func();
       virtual void key_down_func();
       virtual void key_up_func();
       virtual void key_char_func();
       virtual void joy_button_down_func();
       virtual void joy_button_up_func();
       virtual void joy_axis_func();
       virtual void joy_config_func();
       virtual void user_event_func();
       virtual void native_menu_click_func();
       virtual void receive_signal(int signal, void *data); // experimental
       virtual void receive_signal(std::string const &signal, void *data); // I'm likin it
       // TODO!! signal should no longer be a reference, just a const std::string
       // TODO!! signal should no longer be a reference, just a const std::string

       //ALLEGRO_COLOR background_color;
       //bool drawing;
       //bool updating;
       //bool input_active;

       static void bring_to_front(Screen *s);
       void set_on_display(Display *display);
       static int get_num_screens();
       Screen(Display *display=nullptr);
       virtual ~Screen();
    };




    #endif
}