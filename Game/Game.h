#include "../Graphics/Display.h" 
#include "../Util/Types.h"
#include <functional>

class Game {
public:
    Game();
    inline void OnLoad( std::function<void(Game*)> cb ) {
        load = cb;
    };
    inline void OnInput( std::function<void(Game*)> cb ) {
        input = cb;
    }
    inline void OnUpdate( std::function<void(Game*,float)> cb ) {
        update = cb;    
    };
    inline void OnRender( std::function<void(Game*)> cb ) {
        render = cb;    
    };
    void Start();
    //virtual ~Game();
    
    inline Display* GetDisplay() { return this->display; };

private:
    void Loop();
    std::function<void(Game*)>       load;
    std::function<void(Game*)>       input;
    std::function<void(Game*,float)> update;
    std::function<void(Game*)>       render;
    Display *display;
};
