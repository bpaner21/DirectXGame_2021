#pragma once
#include <d3d11.h>

class GraphicsEngine
{
public:
	GraphicsEngine();
	~GraphicsEngine();

	// Initialize the graphics engine and DirectX 11 Device
	bool init();

	// Release all the resources loaded
	bool release();

	static GraphicsEngine* get();

protected:

private:
	ID3D11Device* m_d3d_device = nullptr;
	D3D_FEATURE_LEVEL m_feature_level;
	ID3D11DeviceContext* m_imm_context = nullptr;
};

