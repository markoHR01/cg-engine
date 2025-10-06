#include "engine/vulkan_context.hpp"
#include <cstdlib>

VulkanContext::VulkanContext() {
    createInstance();
    pickPhysicalDevice();
}

VulkanContext::~VulkanContext() {
    if (instance_ != VK_NULL_HANDLE) {
        vkDestroyInstance(instance_, nullptr);
        std::cout << "Destroyed Vulkan instance.\n";
    }
}

VkInstance VulkanContext::getInstance() const {
    return instance_;
}

void VulkanContext::createInstance() {
    VkApplicationInfo appInfo{
        .sType = VK_STRUCTURE_TYPE_APPLICATION_INFO,
        .pApplicationName = "cg-engine",
        .applicationVersion = VK_MAKE_VERSION(1, 0, 0),
        .pEngineName = "cg-engine",
        .engineVersion = VK_MAKE_VERSION(1, 0, 0),
        .apiVersion = VK_API_VERSION_1_3
    };

    VkInstanceCreateInfo createInfo{
        .sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO,
        .pApplicationInfo = &appInfo
    };

    if (vkCreateInstance(&createInfo, nullptr, &instance_) != VK_SUCCESS) {
        std::cerr << "Failed to create Vulkan instance!\n";
        std::exit(EXIT_FAILURE);
    }
}

void VulkanContext::pickPhysicalDevice() {
    uint32_t deviceCount = 0;
    vkEnumeratePhysicalDevices(instance_, &deviceCount, nullptr);

    if (deviceCount == 0) {
        std::cerr << "No Vulkan-compatible GPU found!\n";
        std::exit(EXIT_FAILURE);
    }

    std::vector<VkPhysicalDevice> devices(deviceCount);
    vkEnumeratePhysicalDevices(instance_, &deviceCount, devices.data());

    physicalDevice_ = devices[0];
    std::cout << "Selected first Vulkan-capable GPU.\n";
}
