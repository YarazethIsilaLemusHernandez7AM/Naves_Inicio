
class CGame
{
public:
	enum Estado{

		estado_iniciado,
		estado_menu,
		estado_jugando,
		estado_terminado,
		estado_finalizado
	};
	bool Start();
	static CGame instanceGame;

	CGame();
	void Finalize();

private:
	Estado estado;  
};