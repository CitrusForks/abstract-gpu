#ifndef AGPU_TEXTURE_FORMATS_HPP
#define AGPU_TEXTURE_FORMATS_HPP

#include <AGPU/agpu.h>
#include "../Common/texture_formats_common.hpp"

inline GLenum findTextureTarget(agpu_texture_description *description)
{
    assert(description);
    switch(description->type)
    {
    case AGPU_TEXTURE_1D:
        if(description->depthOrArraySize > 1)
            return GL_TEXTURE_1D_ARRAY;
        else
            return GL_TEXTURE_1D;
    case AGPU_TEXTURE_2D:
        if(description->depthOrArraySize > 1)
            return GL_TEXTURE_2D_ARRAY;
        else
            return GL_TEXTURE_2D;
    case AGPU_TEXTURE_3D:
        return GL_TEXTURE_3D;
    case AGPU_TEXTURE_CUBE:
        return GL_TEXTURE_CUBE_MAP;
    case AGPU_TEXTURE_BUFFER:
        return GL_TEXTURE_BUFFER;
    default:
        abort();

    }
}

inline GLenum mapInternalTextureFormat(agpu_texture_format format)
{
    switch(format)
    {
    case AGPU_TEXTURE_FORMAT_R32G32B32A32_TYPELESS:        return GL_RGBA32UI;
	case AGPU_TEXTURE_FORMAT_R32G32B32A32_FLOAT:           return GL_RGBA32F;
	case AGPU_TEXTURE_FORMAT_R32G32B32A32_UINT:            return GL_RGBA32UI;
	case AGPU_TEXTURE_FORMAT_R32G32B32A32_SINT:            return GL_RGBA32I;

	case AGPU_TEXTURE_FORMAT_R32G32B32_TYPELESS:           return GL_RGB32UI;
	case AGPU_TEXTURE_FORMAT_R32G32B32_FLOAT:              return GL_RGB32F;
	case AGPU_TEXTURE_FORMAT_R32G32B32_UINT:               return GL_RGB32UI;
	case AGPU_TEXTURE_FORMAT_R32G32B32_SINT:               return GL_RGB32I;

	case AGPU_TEXTURE_FORMAT_R16G16B16A16_TYPELESS:        return GL_RGBA16UI;
	case AGPU_TEXTURE_FORMAT_R16G16B16A16_FLOAT:           return GL_RGBA16F;
	case AGPU_TEXTURE_FORMAT_R16G16B16A16_UNORM:           return GL_RGBA16;
	case AGPU_TEXTURE_FORMAT_R16G16B16A16_UINT:            return GL_RGBA16UI;
	case AGPU_TEXTURE_FORMAT_R16G16B16A16_SNORM:           return GL_RGBA16_SNORM;
	case AGPU_TEXTURE_FORMAT_R16G16B16A16_SINT:            return GL_RGBA16I;

	case AGPU_TEXTURE_FORMAT_R32G32_TYPELESS:              return GL_RG32UI;
	case AGPU_TEXTURE_FORMAT_R32G32_FLOAT:                 return GL_RG32F;
	case AGPU_TEXTURE_FORMAT_R32G32_UINT:                  return GL_RG32UI;
	case AGPU_TEXTURE_FORMAT_R32G32_SINT:                  return GL_RG32I;
	case AGPU_TEXTURE_FORMAT_D32_FLOAT_S8X24_UINT:         return GL_DEPTH32F_STENCIL8;

	case AGPU_TEXTURE_FORMAT_R10G10B10A2_TYPELESS:         return GL_RGB10_A2UI;
	case AGPU_TEXTURE_FORMAT_R10G10B10A2_UNORM:            return GL_RGB10_A2;
	case AGPU_TEXTURE_FORMAT_R10G10B10A2_UINT:             return GL_RGB10_A2UI;
	case AGPU_TEXTURE_FORMAT_R11G11B10A2_FLOAT:            return GL_R11F_G11F_B10F;

	case AGPU_TEXTURE_FORMAT_R8G8B8A8_TYPELESS:            return GL_RGBA8;
	case AGPU_TEXTURE_FORMAT_R8G8B8A8_UNORM:               return GL_RGBA8;
	case AGPU_TEXTURE_FORMAT_R8G8B8A8_UNORM_SRGB:          return GL_SRGB8_ALPHA8;
	case AGPU_TEXTURE_FORMAT_R8G8B8A8_UINT:                return GL_RGBA8UI;
	case AGPU_TEXTURE_FORMAT_R8G8B8A8_SNORM:               return GL_RGBA8_SNORM;
	case AGPU_TEXTURE_FORMAT_R8G8B8A8_SINT:                return GL_RGBA8I;

	case AGPU_TEXTURE_FORMAT_R16G16_TYPELESS:              return GL_RG16;
	case AGPU_TEXTURE_FORMAT_R16G16_FLOAT:                 return GL_RG16F;
	case AGPU_TEXTURE_FORMAT_R16G16_UNORM:                 return GL_RG16;
	case AGPU_TEXTURE_FORMAT_R16G16_UINT:                  return GL_RG16UI;
	case AGPU_TEXTURE_FORMAT_R16G16_SNORM:                 return GL_RG16_SNORM;
    case AGPU_TEXTURE_FORMAT_R16G16_SINT:                  return GL_RG16I;

	case AGPU_TEXTURE_FORMAT_R32_TYPELESS:                 return GL_R32UI;
	case AGPU_TEXTURE_FORMAT_D32_FLOAT:                    return GL_DEPTH_COMPONENT32F;
	case AGPU_TEXTURE_FORMAT_R32_FLOAT:                    return GL_R32F;
	case AGPU_TEXTURE_FORMAT_R32_UINT:                     return GL_R32UI;
	case AGPU_TEXTURE_FORMAT_R32_SINT:                     return GL_R32I;

	case AGPU_TEXTURE_FORMAT_R24G8_TYPELESS:               return GL_DEPTH24_STENCIL8;
	case AGPU_TEXTURE_FORMAT_D24_UNORM_S8_UINT:            return GL_DEPTH24_STENCIL8;
	case AGPU_TEXTURE_FORMAT_R24_UNORM_X8_TYPELESS:        return GL_DEPTH24_STENCIL8;
	case AGPU_TEXTURE_FORMAT_X24TG8_UINT:                  return GL_DEPTH24_STENCIL8;
	case AGPU_TEXTURE_FORMAT_R8G8_TYPELESS:                return GL_RG8;
	case AGPU_TEXTURE_FORMAT_R8G8_UNORM:                   return GL_RG8;
	case AGPU_TEXTURE_FORMAT_R8G8_UINT:                    return GL_RG8UI;
	case AGPU_TEXTURE_FORMAT_R8G8_SNORM:                   return GL_RG8_SNORM;
	case AGPU_TEXTURE_FORMAT_R8G8_SINT:                    return GL_RG8I;

	case AGPU_TEXTURE_FORMAT_R16_TYPELESS:                 return GL_R16;
	case AGPU_TEXTURE_FORMAT_R16_FLOAT:                    return GL_R16F;
	case AGPU_TEXTURE_FORMAT_D16_UNORM:                    return GL_DEPTH_COMPONENT16;
	case AGPU_TEXTURE_FORMAT_R16_UNORM:                    return GL_R16;
	case AGPU_TEXTURE_FORMAT_R16_UINT:                     return GL_R16UI;
	case AGPU_TEXTURE_FORMAT_R16_SNORM:                    return GL_R16_SNORM;
	case AGPU_TEXTURE_FORMAT_R16_SINT:                     return GL_R16I;

	case AGPU_TEXTURE_FORMAT_R8_TYPELESS:                  return GL_R8;
	case AGPU_TEXTURE_FORMAT_R8_UNORM:                     return GL_R8;
	case AGPU_TEXTURE_FORMAT_R8_UINT:                      return GL_R8UI;
	case AGPU_TEXTURE_FORMAT_R8_SNORM:                     return GL_R8_SNORM;
	case AGPU_TEXTURE_FORMAT_R8_SINT:                      return GL_R8I;
	case AGPU_TEXTURE_FORMAT_A8_UNORM:                     return GL_R8;

	case AGPU_TEXTURE_FORMAT_BC1_TYPELESS:                 return GL_COMPRESSED_RGB_S3TC_DXT1_EXT;
	case AGPU_TEXTURE_FORMAT_BC1_UNORM:                    return GL_COMPRESSED_RGB_S3TC_DXT1_EXT;
	case AGPU_TEXTURE_FORMAT_BC1_UNORM_SRGB:               return GL_COMPRESSED_SRGB_S3TC_DXT1_EXT;

	case AGPU_TEXTURE_FORMAT_BC2_TYPELESS:                 return GL_COMPRESSED_RGBA_S3TC_DXT3_EXT;
	case AGPU_TEXTURE_FORMAT_BC2_UNORM:                    return GL_COMPRESSED_RGBA_S3TC_DXT3_EXT;
	case AGPU_TEXTURE_FORMAT_BC2_UNORM_SRGB:               return GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT3_EXT;

	case AGPU_TEXTURE_FORMAT_BC3_TYPELESS:                 return GL_COMPRESSED_RGBA_S3TC_DXT5_EXT;
	case AGPU_TEXTURE_FORMAT_BC3_UNORM:                    return GL_COMPRESSED_RGBA_S3TC_DXT5_EXT;
	case AGPU_TEXTURE_FORMAT_BC3_UNORM_SRGB:               return GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT5_EXT;

/*
	case AGPU_TEXTURE_FORMAT_BC4_TYPELESS = 79,
	case AGPU_TEXTURE_FORMAT_BC4_UNORM = 80,
	case AGPU_TEXTURE_FORMAT_BC4_SNORM = 81,

	case AGPU_TEXTURE_FORMAT_BC5_TYPELESS = 82,
	case AGPU_TEXTURE_FORMAT_BC5_UNORM = 83,
	case AGPU_TEXTURE_FORMAT_BC5_SNORM = 84,
*/

	case AGPU_TEXTURE_FORMAT_B5G6R5_UNORM:                 return GL_RGB5;
	case AGPU_TEXTURE_FORMAT_B5G5R5A1_UNORM:               return GL_RGB5_A1;

	case AGPU_TEXTURE_FORMAT_B8G8R8A8_UNORM:               return GL_RGBA8;
	case AGPU_TEXTURE_FORMAT_B8G8R8X8_UNORM:               return GL_RGB8;

	case AGPU_TEXTURE_FORMAT_B8G8R8A8_TYPELESS:            return GL_RGBA8;
	case AGPU_TEXTURE_FORMAT_B8G8R8A8_UNORM_SRGB:          return GL_SRGB8_ALPHA8;
	case AGPU_TEXTURE_FORMAT_B8G8R8X8_TYPELESS:            return GL_RGB8;
	case AGPU_TEXTURE_FORMAT_B8G8R8X8_UNORM_SRGB:          return GL_SRGB8;

    default:
        abort();
    }
}

inline GLenum mapExternalFormat(agpu_texture_format format)
{
    switch(format)
    {
    case AGPU_TEXTURE_FORMAT_R32G32B32A32_TYPELESS:
	case AGPU_TEXTURE_FORMAT_R32G32B32A32_FLOAT:
	case AGPU_TEXTURE_FORMAT_R32G32B32A32_UINT:
	case AGPU_TEXTURE_FORMAT_R32G32B32A32_SINT:
        return GL_RGBA;

	case AGPU_TEXTURE_FORMAT_R32G32B32_TYPELESS:
	case AGPU_TEXTURE_FORMAT_R32G32B32_FLOAT:
	case AGPU_TEXTURE_FORMAT_R32G32B32_UINT:
	case AGPU_TEXTURE_FORMAT_R32G32B32_SINT:
        return GL_RGB;

	case AGPU_TEXTURE_FORMAT_R16G16B16A16_TYPELESS:
	case AGPU_TEXTURE_FORMAT_R16G16B16A16_FLOAT:
	case AGPU_TEXTURE_FORMAT_R16G16B16A16_UNORM:
	case AGPU_TEXTURE_FORMAT_R16G16B16A16_UINT:
	case AGPU_TEXTURE_FORMAT_R16G16B16A16_SNORM:
	case AGPU_TEXTURE_FORMAT_R16G16B16A16_SINT:
        return GL_RGBA;

	case AGPU_TEXTURE_FORMAT_R32G32_TYPELESS:
	case AGPU_TEXTURE_FORMAT_R32G32_FLOAT:
	case AGPU_TEXTURE_FORMAT_R32G32_UINT:
	case AGPU_TEXTURE_FORMAT_R32G32_SINT:
        return GL_RG;

	case AGPU_TEXTURE_FORMAT_R32G8X24_TYPELESS:
        return GL_RG;

	case AGPU_TEXTURE_FORMAT_D32_FLOAT_S8X24_UINT:
        return GL_DEPTH_STENCIL;

	case AGPU_TEXTURE_FORMAT_R10G10B10A2_TYPELESS:
	case AGPU_TEXTURE_FORMAT_R10G10B10A2_UNORM:
	case AGPU_TEXTURE_FORMAT_R10G10B10A2_UINT:
	case AGPU_TEXTURE_FORMAT_R11G11B10A2_FLOAT:
        return GL_RGBA;

	case AGPU_TEXTURE_FORMAT_R8G8B8A8_TYPELESS:
	case AGPU_TEXTURE_FORMAT_R8G8B8A8_UNORM:
	case AGPU_TEXTURE_FORMAT_R8G8B8A8_UNORM_SRGB:
	case AGPU_TEXTURE_FORMAT_R8G8B8A8_UINT:
	case AGPU_TEXTURE_FORMAT_R8G8B8A8_SNORM:
	case AGPU_TEXTURE_FORMAT_R8G8B8A8_SINT:
        return GL_RGBA;

	case AGPU_TEXTURE_FORMAT_R16G16_TYPELESS:
	case AGPU_TEXTURE_FORMAT_R16G16_FLOAT:
	case AGPU_TEXTURE_FORMAT_R16G16_UNORM:
	case AGPU_TEXTURE_FORMAT_R16G16_UINT:
	case AGPU_TEXTURE_FORMAT_R16G16_SNORM:
	case AGPU_TEXTURE_FORMAT_R16G16_SINT:
        return GL_RG;

    case AGPU_TEXTURE_FORMAT_D32_FLOAT:
        return GL_DEPTH_COMPONENT;
	case AGPU_TEXTURE_FORMAT_R32_TYPELESS:
	case AGPU_TEXTURE_FORMAT_R32_FLOAT:
	case AGPU_TEXTURE_FORMAT_R32_UINT:
	case AGPU_TEXTURE_FORMAT_R32_SINT:
        return GL_RED;

	case AGPU_TEXTURE_FORMAT_R24G8_TYPELESS:
        return GL_RED;
	case AGPU_TEXTURE_FORMAT_D24_UNORM_S8_UINT:
        return GL_DEPTH_STENCIL;

	case AGPU_TEXTURE_FORMAT_R8G8_TYPELESS:
	case AGPU_TEXTURE_FORMAT_R8G8_UNORM:
	case AGPU_TEXTURE_FORMAT_R8G8_UINT:
	case AGPU_TEXTURE_FORMAT_R8G8_SNORM:
	case AGPU_TEXTURE_FORMAT_R8G8_SINT:
        return GL_RG;

    case AGPU_TEXTURE_FORMAT_D16_UNORM:
        return GL_DEPTH_COMPONENT;

	case AGPU_TEXTURE_FORMAT_R16_TYPELESS:
	case AGPU_TEXTURE_FORMAT_R16_FLOAT:
	case AGPU_TEXTURE_FORMAT_R16_UNORM:
	case AGPU_TEXTURE_FORMAT_R16_UINT:
	case AGPU_TEXTURE_FORMAT_R16_SNORM:
	case AGPU_TEXTURE_FORMAT_R16_SINT:
        return GL_RED;

	case AGPU_TEXTURE_FORMAT_R8_TYPELESS:
	case AGPU_TEXTURE_FORMAT_R8_UNORM:
	case AGPU_TEXTURE_FORMAT_R8_UINT:
	case AGPU_TEXTURE_FORMAT_R8_SNORM:
	case AGPU_TEXTURE_FORMAT_R8_SINT:
	case AGPU_TEXTURE_FORMAT_A8_UNORM:
    case AGPU_TEXTURE_FORMAT_R1_UNORM:
        return GL_RED;

/*	case AGPU_TEXTURE_FORMAT_BC1_TYPELESS = 70,
	case AGPU_TEXTURE_FORMAT_BC1_UNORM = 71,
	case AGPU_TEXTURE_FORMAT_BC1_UNORM_SRGB = 72,
	case AGPU_TEXTURE_FORMAT_BC2_TYPELESS = 73,
	case AGPU_TEXTURE_FORMAT_BC2_UNORM = 74,
	case AGPU_TEXTURE_FORMAT_BC2_UNORM_SRGB = 75,
	case AGPU_TEXTURE_FORMAT_BC3_TYPELESS = 76,
	case AGPU_TEXTURE_FORMAT_BC3_UNORM = 77,
	case AGPU_TEXTURE_FORMAT_BC3_UNORM_SRGB = 78,
	case AGPU_TEXTURE_FORMAT_BC4_TYPELESS = 79,
	case AGPU_TEXTURE_FORMAT_BC4_UNORM = 80,
	case AGPU_TEXTURE_FORMAT_BC4_SNORM = 81,
	case AGPU_TEXTURE_FORMAT_BC5_TYPELESS = 82,
	case AGPU_TEXTURE_FORMAT_BC5_UNORM = 83,
	case AGPU_TEXTURE_FORMAT_BC5_SNORM = 84,
*/

	case AGPU_TEXTURE_FORMAT_B5G6R5_UNORM:
        return GL_BGR;
	case AGPU_TEXTURE_FORMAT_B5G5R5A1_UNORM:
        return GL_BGRA;
	case AGPU_TEXTURE_FORMAT_B8G8R8A8_UNORM:
        return GL_BGRA;
	case AGPU_TEXTURE_FORMAT_B8G8R8X8_UNORM:
        return GL_BGR;

	case AGPU_TEXTURE_FORMAT_B8G8R8A8_TYPELESS:
	case AGPU_TEXTURE_FORMAT_B8G8R8A8_UNORM_SRGB:
        return GL_BGRA;
	case AGPU_TEXTURE_FORMAT_B8G8R8X8_TYPELESS:
	case AGPU_TEXTURE_FORMAT_B8G8R8X8_UNORM_SRGB:
        return GL_BGR;
    default:
        abort();
    }
}

inline GLenum mapExternalFormatType(agpu_texture_format format)
{
    switch(format)
    {
	case AGPU_TEXTURE_FORMAT_R32G32B32A32_TYPELESS:    return GL_UNSIGNED_INT;
	case AGPU_TEXTURE_FORMAT_R32G32B32A32_FLOAT:       return GL_FLOAT;
	case AGPU_TEXTURE_FORMAT_R32G32B32A32_UINT:        return GL_UNSIGNED_INT;
	case AGPU_TEXTURE_FORMAT_R32G32B32A32_SINT:        return GL_INT;

	case AGPU_TEXTURE_FORMAT_R32G32B32_TYPELESS:       return GL_UNSIGNED_INT;
	case AGPU_TEXTURE_FORMAT_R32G32B32_FLOAT:          return GL_FLOAT;
	case AGPU_TEXTURE_FORMAT_R32G32B32_UINT:           return GL_UNSIGNED_INT;
	case AGPU_TEXTURE_FORMAT_R32G32B32_SINT:           return GL_INT;

	case AGPU_TEXTURE_FORMAT_R16G16B16A16_TYPELESS:    return GL_UNSIGNED_SHORT;
	case AGPU_TEXTURE_FORMAT_R16G16B16A16_FLOAT:       return GL_FLOAT;
	case AGPU_TEXTURE_FORMAT_R16G16B16A16_UNORM:       return GL_UNSIGNED_SHORT;
	case AGPU_TEXTURE_FORMAT_R16G16B16A16_UINT:        return GL_UNSIGNED_SHORT;
	case AGPU_TEXTURE_FORMAT_R16G16B16A16_SNORM:       return GL_SHORT;
	case AGPU_TEXTURE_FORMAT_R16G16B16A16_SINT:        return GL_SHORT;

	case AGPU_TEXTURE_FORMAT_R32G32_TYPELESS:          return GL_UNSIGNED_INT;
	case AGPU_TEXTURE_FORMAT_R32G32_FLOAT:             return GL_FLOAT;
	case AGPU_TEXTURE_FORMAT_R32G32_UINT:              return GL_UNSIGNED_INT;
	case AGPU_TEXTURE_FORMAT_R32G32_SINT:              return GL_INT;
	case AGPU_TEXTURE_FORMAT_R32G8X24_TYPELESS:        return GL_UNSIGNED_INT;

	case AGPU_TEXTURE_FORMAT_D32_FLOAT_S8X24_UINT:             return GL_UNSIGNED_INT;
	case AGPU_TEXTURE_FORMAT_R32_FLOAT_S8X24_TYPELESS:         return GL_UNSIGNED_INT;
	case AGPU_TEXTURE_FORMAT_X32_TYPELESS_G8X24_UINT:          return GL_UNSIGNED_INT;

	case AGPU_TEXTURE_FORMAT_R10G10B10A2_TYPELESS:     return GL_UNSIGNED_INT_10_10_10_2;
	case AGPU_TEXTURE_FORMAT_R10G10B10A2_UNORM:        return GL_UNSIGNED_INT_10_10_10_2;
	case AGPU_TEXTURE_FORMAT_R10G10B10A2_UINT:         return GL_UNSIGNED_INT_10_10_10_2;
	case AGPU_TEXTURE_FORMAT_R11G11B10A2_FLOAT:        return GL_FLOAT;

	case AGPU_TEXTURE_FORMAT_R8G8B8A8_TYPELESS:        return GL_UNSIGNED_BYTE;
	case AGPU_TEXTURE_FORMAT_R8G8B8A8_UNORM:           return GL_UNSIGNED_BYTE;
	case AGPU_TEXTURE_FORMAT_R8G8B8A8_UNORM_SRGB:      return GL_UNSIGNED_BYTE;
	case AGPU_TEXTURE_FORMAT_R8G8B8A8_UINT:            return GL_UNSIGNED_BYTE;
	case AGPU_TEXTURE_FORMAT_R8G8B8A8_SNORM:           return GL_UNSIGNED_BYTE;
	case AGPU_TEXTURE_FORMAT_R8G8B8A8_SINT:            return GL_BYTE;

	case AGPU_TEXTURE_FORMAT_R16G16_TYPELESS:          return GL_UNSIGNED_SHORT;
	case AGPU_TEXTURE_FORMAT_R16G16_FLOAT:             return GL_FLOAT;
	case AGPU_TEXTURE_FORMAT_R16G16_UNORM:             return GL_UNSIGNED_SHORT;
	case AGPU_TEXTURE_FORMAT_R16G16_UINT:              return GL_UNSIGNED_SHORT;
	case AGPU_TEXTURE_FORMAT_R16G16_SNORM:             return GL_SHORT;
	case AGPU_TEXTURE_FORMAT_R16G16_SINT:              return GL_SHORT;

	case AGPU_TEXTURE_FORMAT_R32_TYPELESS:             return GL_UNSIGNED_INT;
	case AGPU_TEXTURE_FORMAT_D32_FLOAT:                return GL_FLOAT;
	case AGPU_TEXTURE_FORMAT_R32_FLOAT:                return GL_FLOAT;
	case AGPU_TEXTURE_FORMAT_R32_UINT:                 return GL_UNSIGNED_INT;
	case AGPU_TEXTURE_FORMAT_R32_SINT:                 return GL_INT;

	case AGPU_TEXTURE_FORMAT_R24G8_TYPELESS:           return GL_UNSIGNED_INT;
	case AGPU_TEXTURE_FORMAT_D24_UNORM_S8_UINT:        return GL_UNSIGNED_INT;
	case AGPU_TEXTURE_FORMAT_R24_UNORM_X8_TYPELESS:    return GL_UNSIGNED_INT;
	case AGPU_TEXTURE_FORMAT_X24TG8_UINT:              return GL_UNSIGNED_INT;

	case AGPU_TEXTURE_FORMAT_R8G8_TYPELESS:            return GL_UNSIGNED_BYTE;
	case AGPU_TEXTURE_FORMAT_R8G8_UNORM:               return GL_UNSIGNED_BYTE;
	case AGPU_TEXTURE_FORMAT_R8G8_UINT:                return GL_UNSIGNED_BYTE;
	case AGPU_TEXTURE_FORMAT_R8G8_SNORM:               return GL_BYTE;
	case AGPU_TEXTURE_FORMAT_R8G8_SINT:                return GL_BYTE;

	case AGPU_TEXTURE_FORMAT_R16_TYPELESS:             return GL_UNSIGNED_SHORT;
	case AGPU_TEXTURE_FORMAT_R16_FLOAT:                return GL_FLOAT;
	case AGPU_TEXTURE_FORMAT_D16_UNORM:                return GL_UNSIGNED_SHORT;
	case AGPU_TEXTURE_FORMAT_R16_UNORM:                return GL_UNSIGNED_SHORT;
	case AGPU_TEXTURE_FORMAT_R16_UINT:                 return GL_UNSIGNED_SHORT;
	case AGPU_TEXTURE_FORMAT_R16_SNORM:                return GL_SHORT;
	case AGPU_TEXTURE_FORMAT_R16_SINT:                 return GL_SHORT;

	case AGPU_TEXTURE_FORMAT_R8_TYPELESS:              return GL_UNSIGNED_SHORT;
	case AGPU_TEXTURE_FORMAT_R8_UNORM:                 return GL_UNSIGNED_SHORT;
	case AGPU_TEXTURE_FORMAT_R8_UINT:                  return GL_UNSIGNED_SHORT;
	case AGPU_TEXTURE_FORMAT_R8_SNORM:                 return GL_UNSIGNED_SHORT;
	case AGPU_TEXTURE_FORMAT_R8_SINT:                  return GL_UNSIGNED_SHORT;
	case AGPU_TEXTURE_FORMAT_A8_UNORM:                 return GL_UNSIGNED_SHORT;
	case AGPU_TEXTURE_FORMAT_R1_UNORM:                 return GL_UNSIGNED_SHORT;

/*	case AGPU_TEXTURE_FORMAT_BC1_TYPELESS = 70,
	case AGPU_TEXTURE_FORMAT_BC1_UNORM = 71,
	case AGPU_TEXTURE_FORMAT_BC1_UNORM_SRGB = 72,
	case AGPU_TEXTURE_FORMAT_BC2_TYPELESS = 73,
	case AGPU_TEXTURE_FORMAT_BC2_UNORM = 74,
	case AGPU_TEXTURE_FORMAT_BC2_UNORM_SRGB = 75,
	case AGPU_TEXTURE_FORMAT_BC3_TYPELESS = 76,
	case AGPU_TEXTURE_FORMAT_BC3_UNORM = 77,
	case AGPU_TEXTURE_FORMAT_BC3_UNORM_SRGB = 78,
	case AGPU_TEXTURE_FORMAT_BC4_TYPELESS = 79,
	case AGPU_TEXTURE_FORMAT_BC4_UNORM = 80,
	case AGPU_TEXTURE_FORMAT_BC4_SNORM = 81,
	case AGPU_TEXTURE_FORMAT_BC5_TYPELESS = 82,
	case AGPU_TEXTURE_FORMAT_BC5_UNORM = 83,
	case AGPU_TEXTURE_FORMAT_BC5_SNORM = 84,
*/

	case AGPU_TEXTURE_FORMAT_B5G6R5_UNORM:             return GL_UNSIGNED_SHORT_5_6_5;
	case AGPU_TEXTURE_FORMAT_B5G5R5A1_UNORM:           return GL_UNSIGNED_SHORT_5_5_5_1;
	case AGPU_TEXTURE_FORMAT_B8G8R8A8_UNORM:           return GL_UNSIGNED_BYTE;
	case AGPU_TEXTURE_FORMAT_B8G8R8X8_UNORM:           return GL_UNSIGNED_BYTE;

	case AGPU_TEXTURE_FORMAT_B8G8R8A8_TYPELESS:
	case AGPU_TEXTURE_FORMAT_B8G8R8A8_UNORM_SRGB:
	case AGPU_TEXTURE_FORMAT_B8G8R8X8_TYPELESS:
	case AGPU_TEXTURE_FORMAT_B8G8R8X8_UNORM_SRGB:
        return GL_UNSIGNED_BYTE;


    default:
        return GL_UNSIGNED_BYTE;
    }
}

#endif //AGPU_TEXTURE_FORMATS_HPP
