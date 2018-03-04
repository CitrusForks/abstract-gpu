#ifndef AGPU_PIPELINE_STATE_HPP_
#define AGPU_PIPELINE_STATE_HPP_

#include "device.hpp"
#include "shader.hpp"

struct CommandListExecutionContext;
struct agpu_shader_forSignature;

struct _agpu_pipeline_state: public Object<_agpu_pipeline_state>
{
public:
    _agpu_pipeline_state();

    void lostReferences();

    agpu_int getUniformLocation ( agpu_cstring name );
    void activateShaderResourcesOn(CommandListExecutionContext *context);

public:
    agpu_device *device;
    agpu_shader_signature *shaderSignature;
    std::vector<agpu_shader_forSignature*> shaderInstances;
    std::vector<MappedTextureWithSamplerCombination> mappedTextureWithSamplerCombinations;
    GLuint programHandle;

    // States
    agpu_bool depthEnabled;
    agpu_bool depthWriteMask;
    GLenum depthFunction;

    // Face culling
    GLenum frontFaceWinding;
    GLenum cullingMode;

    // Color buffer
    agpu_bool blendingEnabled;
    agpu_bool redMask;
    agpu_bool greenMask;
    agpu_bool blueMask;
    agpu_bool alphaMask;
    GLenum sourceBlendFactor;
    GLenum destBlendFactor;
    GLenum blendOperation;
    GLenum sourceBlendFactorAlpha;
    GLenum destBlendFactorAlpha;
    GLenum blendOperationAlpha;

    // Stencil testing
    agpu_bool stencilEnabled;
    int stencilWriteMask;
    int stencilReadMask;

    GLenum stencilFrontFailOp;
    GLenum stencilFrontDepthFailOp;
    GLenum stencilFrontDepthPassOp;
    GLenum stencilFrontFunc;

    GLenum stencilBackFailOp;
    GLenum stencilBackDepthFailOp;
    GLenum stencilBackDepthPassOp;
    GLenum stencilBackFunc;

    // Alpha testing
    bool alphaTestEnabled;
	GLenum alphaTestFunction;

    // Miscellaneous
    int renderTargetCount;
    bool hasSRGBTarget;
    agpu_primitive_topology primitiveTopology;

public:
    void activate();
    void enableState(bool enabled, GLenum state);
    void updateStencilReference(int reference);
};


#endif //AGPU_PIPELINE_STATE_HPP_
