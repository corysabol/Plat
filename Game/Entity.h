#include <glm/glm.hpp>

class Entity {
    /*
     * Entity is a simple class which implements the follwing funcitons:
     *  - Update: contains entity logic, should be called in game Update() lambda
     *  - Render: contains entity rendering calls, should be called in game Render()
     */
public:
    Entity();

    //SetMesh();
    //GetMesh();
    inline void SetPos( glm::vec3 pos ) { this->pos = pos; };
    inline glm::vec3 GetPos() { return this->pos; };

private:
    /*
     * We might want to have the following memebers:
     *  - Mesh: the mesh of the Entity
     *  - Pos: the world position of the Entity
     */
    //Mesh* mesh;
    glm::vec3 pos;
};
