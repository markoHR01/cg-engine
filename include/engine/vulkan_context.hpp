#pragma once
#include <vulkan/vulkan.h>
#include <vector>
#include <string>
#include <iostream>
#include <cstdint>

class VulkanContext {
public:
    VulkanContext();
    ~VulkanContext();

    VulkanContext(const VulkanContext&) = delete;
    VulkanContext& operator=(const VulkanContext&) = delete;

    VkInstance getInstance() const;

private:
    void createInstance();
    void pickPhysicalDevice();

    VkInstance instance_{};
    VkPhysicalDevice physicalDevice_{VK_NULL_HANDLE};
};
