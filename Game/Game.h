#include "../Graphics/Display.h" 
#include "../Util/Types.h"
#include <functional>

class Game {
public:
    Game();
    inline void setLoad( std::function<void(Game*)> cb ) {
        load = cb;
    };
    inline void setUpdate( std::function<void(Game*,float)> cb ) {
        update = cb;    
    };
    inline void setRender( std::function<void(Game*)> cb ) {
        render = cb;    
    };
    void start();
    //virtual ~Game();
    
    // should be just expose a bunch of functionality here?
    // Graphics stuff
    void ClearDisplay( int color );

    inline Display* GetDisplay() { return this->display; };

private:
    void loop();
    std::function<void(Game*)>       load;
    std::function<void(Game*,float)> update;
    std::function<void(Game*)>       render;
    Display *display;
};
