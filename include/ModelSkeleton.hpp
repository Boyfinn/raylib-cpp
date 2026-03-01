#ifndef RAYLIB_CPP_INCLUDE_MODELSKELETON_HPP_
#define RAYLIB_CPP_INCLUDE_MODELSKELETON_HPP_

#include <string>
#include <vector>

#include "./raylib-cpp-utils.hpp"
#include "./raylib.hpp"

namespace raylib {
/**
 * Model skeleton
 */
class ModelSkeleton : public ::ModelSkeleton {
public:
    ModelSkeleton() {
        boneCount = 0;
        bones = nullptr;
        bindPose = nullptr;
    }

    ModelSkeleton(const ::ModelSkeleton& skeleton) { set(skeleton); }

    ModelSkeleton(int boneCount, ::BoneInfo* bones, ::ModelAnimPose bindPose) {
        this->boneCount = boneCount;
        this->bones = bones;
        this->bindPose = bindPose;
    }

    /**
     * Copy a model skeleton from another model skeleton.
     */
    ModelSkeleton(const ModelSkeleton& skeleton) { set(skeleton); }

    /**
     * Move constructor.
     */
    ModelSkeleton(ModelSkeleton&& other) noexcept {
        set(other);

        other.boneCount = 0;
        other.bones = nullptr;
        other.bindPose = nullptr;
    }

    GETTERSETTER(int, BoneCount, boneCount)
    GETTERSETTER(::BoneInfo*, Bones, bones)
    GETTERSETTER(::ModelAnimPose, BindPose, bindPose)

    ModelSkeleton& operator=(const ::ModelSkeleton& skeleton) {
        set(skeleton);
        return *this;
    }

    ModelSkeleton& operator=(const ModelSkeleton& skeleton) {
        set(skeleton);
        return *this;
    }

    ModelSkeleton& operator=(ModelSkeleton&& other) noexcept {
        if (this == &other) {
            return *this;
        }

        set(other);

        other.boneCount = 0;
        other.bones = nullptr;
        other.bindPose = nullptr;

        return *this;
    }
protected:
    void set(const ::ModelSkeleton& skeleton) {
        boneCount = skeleton.boneCount;
        bones = skeleton.bones;
        bindPose = skeleton.bindPose;
    }
};
} // namespace raylib

using RModelSkeleton = raylib::ModelSkeleton;

#endif // RAYLIB_CPP_INCLUDE_MODELSKELETON_HPP_
