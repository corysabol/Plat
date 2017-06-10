#include "../Graphics/Display.h" 
#include "../Util/Types.h"

class Game {
public:
    Game();
    inline void setLoad( callback_t cb ) {
        load_p = cb;
    };
    inline void setUpdate( callback_f_t cb ) {
        update_p = cb;    
    };
    inline void setRender( callback_t cb ) {
        render_p = cb;    
    };
    void start();

private:
    void loop();
    callback_t      load_p;
    callback_f_t    update_p;
    callback_t      render_p;
};
