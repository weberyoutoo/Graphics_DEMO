#pragma once

#include <vector>
#include "Shader.h"
#include "SceneManager.h"
#include "DynamicSceneObject.h"
#include "IndrectSceneObject.h"
#include "G_BufferSetting.h"
#include "DirectObject.h"
#include "terrain\TerrainSceneObject.h"


class SceneRenderer
{
public:
	SceneRenderer();
	virtual ~SceneRenderer();

private:
	ShaderProgram *m_shaderProgram = nullptr;
	glm::mat4 m_projMat;
	glm::mat4 m_viewMat;
	glm::mat4 m_L1projMat;
	glm::mat4 m_L1viewMat;
	glm::mat4 m_L2projMat;
	glm::mat4 m_L2viewMat;
	glm::mat4 m_L3projMat;
	glm::mat4 m_L3viewMat;
	int m_frameWidth;
	int m_frameHeight;	

	std::vector<DynamicSceneObject*> m_dynamicSOs;
	TerrainSceneObject* m_terrainSO = nullptr;
	IndrectSceneObject* m_indrectSO = nullptr;
	DirectObject* directObject = nullptr;

public:
	void resize(const int w, const int h);
	bool initialize(const int w, const int h, ShaderProgram* shaderProgram);

	void setProjection(const glm::mat4 &proj);
	void setView(const glm::mat4 &view);
	void setViewport(const int x, const int y, const int w, const int h);
	void appendDynamicSceneObject(DynamicSceneObject *obj);
	void appendTerrainSceneObject(TerrainSceneObject* tSO);
	void appendIndrectSceneObject(IndrectSceneObject* iSO);
	void appendDircectObject(DirectObject* dO);

	void setLProjection(const glm::mat4& proj1, const glm::mat4& proj2, const glm::mat4& proj3);
	void setLView(const glm::mat4& view1, const glm::mat4& view2, const glm::mat4& view3);
	float mp=0.0;

// pipeline
public:
	void startNewFrame();
	void renderPass();

private:
	void clear(const glm::vec4 &clearColor = glm::vec4(0.0, 0.0, 0.0, 1.0), const float depth = 1.0);
	bool setUpShader();
};

