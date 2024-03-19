/**
* @project: Overload
* @author: Overload Tech.
* @licence: MIT
*/

#pragma once

#include <any>
#include <map>
#include <optional>

#include "OvRendering/Resources/Shader.h"
#include "OvRendering/Resources/Texture.h"
#include "OvRendering/Data/StateMask.h"

namespace OvRendering::Data
{
	/**
	* A material is a combination of a shader and some settings (Material settings and shader settings)
	*/
	class Material
	{
	public:
		/**
		* Creates a material
		* @param p_shader
		*/
		Material(OvRendering::Resources::Shader* p_shader = nullptr);

		/**
		* Defines the shader to attach to this material instance
		* @param p_shader
		*/
		void SetShader(OvRendering::Resources::Shader* p_shader);

		/**
		* Fill uniform with default uniform values
		*/
		void FillUniform();

		/**
		* Bind the material and send its uniform data to the GPU
		* @param p_emptyTexture (The texture to use if a texture uniform is null)
		*/
		void Bind(OvRendering::Resources::Texture* p_emptyTexture = nullptr) const;

		/**
		* Unbind the material
		*/
		void UnBind() const;

		/**
		* Set a shader uniform value
		* @param p_key
		* @param p_value
		*/
		template<typename T> void Set(const std::string p_key, const T& p_value);

		/**
		* Set a shader uniform value
		* @param p_key
		*/
		template<typename T> const T& Get(const std::string p_key) const;

		/**
		* Returns the attached shader
		*/
		OvRendering::Resources::Shader*& GetShader();

		/**
		* Returns true if the material has a shader attached
		*/
		bool HasShader() const;

		/**
		* Returns true if the material is valid
		*/
		bool IsValid() const;

		/**
		* Defines if the material is blendable
		* @param p_blendable
		*/
		void SetBlendable(bool p_blendable);

		/**
		* Defines if the material has backface culling
		* @param p_backfaceCulling
		*/
		void SetBackfaceCulling(bool p_backfaceCulling);

		/**
		* Defines if the material has frontface culling
		* @param p_frontfaceCulling
		*/
		void SetFrontfaceCulling(bool p_frontfaceCulling);

		/**
		* Defines if the material has depth test
		* @param p_depthTest
		*/
		void SetDepthTest(bool p_depthTest);

		/**
		* Defines if the material has depth writting
		* @param p_depthWriting
		*/
		void SetDepthWriting(bool p_depthWriting);

		/**
		* Defines if the material has color writting
		* @param p_colorWriting
		*/
		void SetColorWriting(bool p_colorWriting);

		/**
		* Defines the number of instances
		* @param p_instances
		*/
		void SetGPUInstances(int p_instances);

		/**
		* Returns true if the material is blendable
		*/
		bool IsBlendable() const;

		/**
		* Returns true if the material has backface culling
		*/
		bool HasBackfaceCulling() const;

		/**
		* Returns true if the material has frontface culling
		*/
		bool HasFrontfaceCulling() const;

		/**
		* Returns true if the material has depth test
		*/
		bool HasDepthTest() const;

		/**
		* Returns true if the material has depth writing
		*/
		bool HasDepthWriting() const;

		/**
		* Returns true if the material has color writing
		*/
		bool HasColorWriting() const;

		/**
		* Returns the number of instances
		*/
		int GetGPUInstances() const;

		/**
		* Generate a state mask with the current material settings
		*/
		const StateMask GenerateStateMask() const;

		/**
		* Returns the uniforms data of the material
		*/
		std::map<std::string, std::any>& GetUniformsData();

	protected:
		OvRendering::Resources::Shader* m_shader = nullptr;
		std::map<std::string, std::any> m_uniformsData;

		bool m_blendable = false;
		bool m_backfaceCulling = true;
		bool m_frontfaceCulling = false;
		bool m_depthTest = true;
		bool m_depthWriting = true;
		bool m_colorWriting = true;
		int m_gpuInstances = 1;
	};
}

#include "OvRendering/Data/Material.inl"