/* 

loop.c

*/ 

#include "../../header_files/engine.h"
#include "../../header_files/game.h"

void	core_loop(void *param)
{
	t_engine	*engine;

	engine = (t_engine *)param;
	if (!engine)
		return ;

	if (engine->scene == SCENE_MENU)
	{
		menu_update(engine);
		menu_draw(engine);
	}
	else if (engine->scene == SCENE_SO_LONG)
	{
		so_long_update(engine);
		so_long_draw(engine);
	}
}

/*

src/
├── core/              # engine-agnostic flow
│   └── loop.c
│
├── engine/            # MLX42 only
│   ├── life_cycle.c
│   ├── window.c
│   ├── loop.c
│   └── error.c
│
├── scenes/            # high-level logic
│   ├── menu/
│   │   ├── menu_init.c
│   │   ├── menu_draw.c
│   │   └── menu_update.c
│   └── so_long/
│
├── render/            # engine-agnostic rendering
│   ├── color.c
│   ├── pixel.c
│   ├── fill.c
│   └── rect.c
│
└── main.c


*/