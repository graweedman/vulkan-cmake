
#include "lve_app_base.hpp"

//std
#include <stdexcept>

namespace lve {

  LveAppBase::LveAppBase() {
    createPipelineLayout();
    createPipeline();
    createCommandBuffers();
  }

  LveAppBase::~LveAppBase() {
    vkDestroyPipelineLayout(lveDevice.device(), pipelineLayout, nullptr);
  }

  void LveAppBase::run() {
    while (!lveWindow.shouldClose()) {
      glfwPollEvents();
    }
  }

  void LveAppBase::createPipelineLayout() {
    VkPipelineLayoutCreateInfo pipelineLayoutInfo{};
    pipelineLayoutInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO;
    pipelineLayoutInfo.setLayoutCount = 0;  // Optional
    pipelineLayoutInfo.pSetLayouts = nullptr;  // Optional
    pipelineLayoutInfo.pushConstantRangeCount = 0;  // Optional
    pipelineLayoutInfo.pPushConstantRanges = nullptr;  // Optional
    if(vkCreatePipelineLayout(lveDevice.device(), &pipelineLayoutInfo, nullptr, &pipelineLayout) != VK_SUCCESS){
      throw std::runtime_error("failed to create pipeline layout!");
    }
  }

  void LveAppBase::createPipeline() {
    auto pipelineConfig = LvePipeline::defaultPipelineConfigInfo(lveSwapChain.width(), lveSwapChain.height());
    pipelineConfig.renderPass = lveSwapChain.getRenderPass();
    pipelineConfig.pipelineLayout = pipelineLayout;
    lvePipeline = std::make_unique<LvePipeline>(
      lveDevice,
      "shaders/simple_shader.vert.spv",
      "shaders/simple_shader.frag.spv",
      pipelineConfig
    );
  }

  void LveAppBase::createCommandBuffers() {
    
  }
  void LveAppBase::drawFrame() {

  }
}  // namespace lve