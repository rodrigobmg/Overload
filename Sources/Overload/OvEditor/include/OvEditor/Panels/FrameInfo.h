/**
* @project: Overload
* @author: Overload Tech.
* @licence: MIT
*/

#pragma once

#include <OvTools/Utils/OptRef.h>

#include <OvUI/Panels/PanelWindow.h>
#include <OvUI/Widgets/Texts/TextColored.h>
#include <OvUI/Widgets/Selection/CheckBox.h>
#include <OvUI/Widgets/Visual/Separator.h>

#include <OvEditor/Panels/AView.h>

#include <OvRendering/Data/FrameInfo.h>

namespace OvEditor::Panels
{
	class FrameInfo : public OvUI::Panels::PanelWindow
	{
	public:
		/**
		* Constructor
		* @param p_title
		* @param p_opened
		* @param p_windowSettings
		*/
		FrameInfo(
			const std::string& p_title,
			bool p_opened,
			const OvUI::Settings::PanelWindowSettings& p_windowSettings
		);

		/**
		* Update frame info information
		* @param p_targetView
		*/
		void Update(OvTools::Utils::OptRef<AView> p_targetView);

	private:
		OvUI::Widgets::Texts::Text& m_viewNameText;
		OvUI::Widgets::Visual::Separator& m_separator;
		OvUI::Widgets::Texts::Text& m_batchCountText;
		OvUI::Widgets::Texts::Text& m_instanceCountText;
		OvUI::Widgets::Texts::Text& m_polyCountText;
		OvUI::Widgets::Texts::Text& m_vertexCountText;
	};
}