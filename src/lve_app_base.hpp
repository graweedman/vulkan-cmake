#pragma once

#include "lve_window.hpp"
#include "lve_pipeline.hpp"
#include "lve_swap_chain.hpp"
#include "lve_device.hpp"

//std
#include <memory>
#include <vector>

namespace lve {

class LveAppBase {
 public:
  static constexpr int WIDTH = 800;
  static constexpr int HEIGHT = 600;

  LveAppBase();
  ~LveAppBase();

  LveAppBase(const LveAppBase &) = delete;
  LveAppBase &operator=(const LveAppBase &) = delete;

  void run();

 private:
  void createPipelineLayout();
  void createPipeline();
  void createCommandBuffers();
  void drawFrame();


  LveWindow lveWindow{WIDTH, HEIGHT, "Hello Vulkan!"};
  LveDevice lveDevice{lveWindow};
  LveSwapChain lveSwapChain{lveDevice, lveWindow.getExtent()};
  std::unique_ptr<LvePipeline> lvePipeline;
  VkPipelineLayout pipelineLayout;
  std::vector<VkCommandBuffer> commandBuffers;
};
}  // namespace lve