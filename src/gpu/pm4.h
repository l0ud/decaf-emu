#pragma once
#include <array_view.h>
#include "pm4_format.h"
#include "latte_registers.h"
#include "utils/virtual_ptr.h"

#pragma pack(push, 1)

namespace pm4
{

struct DecafSwapBuffers
{
   static const auto Opcode = Opcode3::DECAF_SWAP_BUFFERS;

   template<typename Serialiser>
   void serialise(Serialiser &se)
   {
   }
};

struct DecafCopyColorToScan
{
   static const auto Opcode = Opcode3::DECAF_COPY_COLOR_TO_SCAN;

   uint32_t scanTarget;
   uint32_t bufferAddr;
   uint32_t aaBufferAddr;
   latte::CB_COLORN_SIZE cb_color_size;
   latte::CB_COLORN_INFO cb_color_info;
   latte::CB_COLORN_VIEW cb_color_view;
   latte::CB_COLORN_MASK cb_color_mask;

   template<typename Serialiser>
   void serialise(Serialiser &se)
   {
      se(scanTarget);
      se(bufferAddr);
      se(aaBufferAddr);
      se(cb_color_size.value);
      se(cb_color_info.value);
      se(cb_color_view.value);
      se(cb_color_mask.value);
   }
};

struct DrawIndexAuto
{
   static const auto Opcode = Opcode3::DRAW_INDEX_AUTO;

   uint32_t indexCount;
   latte::VGT_DRAW_INITIATOR drawInitiator;

   template<typename Serialiser>
   void serialise(Serialiser &se)
   {
      se(indexCount);
      se(drawInitiator.value);
   }
};

struct DrawIndex2
{
   static const auto Opcode = Opcode3::DRAW_INDEX_2;

   uint32_t maxIndices;                      // VGT_DMA_MAX_SIZE
   virtual_ptr<void> addr;                   // VGT_DMA_BASE
   uint32_t numIndices;                      // VGT_DMA_SIZE
   latte::VGT_DRAW_INITIATOR drawInitiator;  // VGT_DRAW_INITIATOR

   template<typename Serialiser>
   void serialise(Serialiser &se)
   {
      uint32_t unusedAddrHi = 0;

      se(maxIndices);
      se(addr);
      se(unusedAddrHi);
      se(numIndices);
      se(drawInitiator.value);
   }
};

struct IndexType
{
   static const auto Opcode = Opcode3::INDEX_TYPE;

   latte::VGT_DMA_INDEX_TYPE type; // VGT_DMA_INDEX_TYPE

   template<typename Serialiser>
   void serialise(Serialiser &se)
   {
      se(type.value);
   }
};

struct NumInstances
{
   static const auto Opcode = Opcode3::NUM_INSTANCES;

   uint32_t count; // VGT_DMA_NUM_INSTANCES

   template<typename Serialiser>
   void serialise(Serialiser &se)
   {
      se(count);
   }
};

struct SetAluConsts
{
   static const auto Opcode = Opcode3::SET_ALU_CONST;

   latte::Register::Value id;
   gsl::array_view<uint32_t> values;

   template<typename Serialiser>
   void serialise(Serialiser &se)
   {
      se.reg(id, latte::Register::AluConstRegisterBase);
      se(values);
   }
};

struct SetConfigReg
{
   static const auto Opcode = Opcode3::SET_CONFIG_REG;

   latte::Register::Value id;
   uint32_t value;

   template<typename Serialiser>
   void serialise(Serialiser &se)
   {
      se.reg(id, latte::Register::ConfigRegisterBase);
      se(value);
   }
};

struct SetConfigRegs
{
   static const auto Opcode = Opcode3::SET_CONFIG_REG;

   latte::Register::Value id;
   gsl::array_view<uint32_t> values;

   template<typename Serialiser>
   void serialise(Serialiser &se)
   {
      se.reg(id, latte::Register::ConfigRegisterBase);
      se(values);
   }
};

struct SetContextReg
{
   static const auto Opcode = Opcode3::SET_CONTEXT_REG;

   latte::Register::Value id;
   uint32_t value;

   template<typename Serialiser>
   void serialise(Serialiser &se)
   {
      se.reg(id, latte::Register::ContextRegisterBase);
      se(value);
   }
};

struct SetContextRegs
{
   static const auto Opcode = Opcode3::SET_CONTEXT_REG;

   latte::Register::Value id;
   gsl::array_view<uint32_t> values;

   template<typename Serialiser>
   void serialise(Serialiser &se)
   {
      se.reg(id, latte::Register::ContextRegisterBase);
      se(values);
   }
};

struct SetControlConstant
{
   static const auto Opcode = Opcode3::SET_CTL_CONST;

   uint32_t id;
   uint32_t value;

   template<typename Serialiser>
   void serialise(Serialiser &se)
   {
      se.reg(id, latte::Register::ControlRegisterBase);
      se(value);
   }
};

struct SetControlConstants
{
   static const auto Opcode = Opcode3::SET_CTL_CONST;

   uint32_t id;
   gsl::array_view<uint32_t> values;

   template<typename Serialiser>
   void serialise(Serialiser &se)
   {
      se.reg(id, latte::Register::ControlRegisterBase);
      se(values);
   }
};

struct SetLoopConst
{
   static const auto Opcode = Opcode3::SET_LOOP_CONST;

   latte::Register::Value id;
   uint32_t value;

   template<typename Serialiser>
   void serialise(Serialiser &se)
   {
      se.reg(id, latte::Register::LoopConstRegisterBase);
      se(value);
   }
};

struct SetLoopConsts
{
   static const auto Opcode = Opcode3::SET_LOOP_CONST;

   latte::Register::Value id;
   gsl::array_view<uint32_t> values;

   template<typename Serialiser>
   void serialise(Serialiser &se)
   {
      se.reg(id, latte::Register::LoopConstRegisterBase);
      se(values);
   }
};

struct SetSamplerAttrib
{
   static const auto Opcode = Opcode3::SET_SAMPLER;

   uint32_t id;
   latte::SQ_TEX_SAMPLER_WORD0_0 word0;
   latte::SQ_TEX_SAMPLER_WORD1_0 word1;
   latte::SQ_TEX_SAMPLER_WORD2_0 word2;

   template<typename Serialiser>
   void serialise(Serialiser &se)
   {
      se.reg(id, latte::Register::SamplerRegisterBase);
      se(word0.value);
      se(word1.value);
      se(word2.value);
   }
};

struct SetSamplers
{
   static const auto Opcode = Opcode3::SET_SAMPLER;

   latte::Register::Value id;
   gsl::array_view<uint32_t> values;

   template<typename Serialiser>
   void serialise(Serialiser &se)
   {
      se.reg(id, latte::Register::SamplerRegisterBase);
      se(values);
   }
};

struct SetVtxResource
{
   static const auto Opcode = Opcode3::SET_RESOURCE;

   uint32_t id;
   virtual_ptr<const void> baseAddress;
   uint32_t size;
   latte::SQ_VTX_CONSTANT_WORD2_0 word2;
   latte::SQ_VTX_CONSTANT_WORD3_0 word3;
   latte::SQ_VTX_CONSTANT_WORD6_0 word6;

   template<typename Serialiser>
   void serialise(Serialiser &se)
   {
      uint32_t unusedWord4 = 0;
      uint32_t unusedWord5 = 0;

      se.reg(id, latte::Register::ResourceRegisterBase);
      se(baseAddress);
      se(size);
      se(word2.value);
      se(word3.value);
      se(unusedWord4);
      se(unusedWord5);
      se(word6.value);
   }
};

struct SetTexResource
{
   static const auto Opcode = Opcode3::SET_RESOURCE;

   uint32_t id;
   latte::SQ_TEX_RESOURCE_WORD0_0 word0;
   latte::SQ_TEX_RESOURCE_WORD1_0 word1;
   virtual_ptr<void> baseAddress;
   virtual_ptr<void> mipAddress;
   latte::SQ_TEX_RESOURCE_WORD4_0 word4;
   latte::SQ_TEX_RESOURCE_WORD5_0 word5;
   latte::SQ_TEX_RESOURCE_WORD6_0 word6;

   template<typename Serialiser>
   void serialise(Serialiser &se)
   {
      se.reg(id, latte::Register::ResourceRegisterBase);
      se(word0.value);
      se(word1.value);
      se(baseAddress);
      se(mipAddress);
      se(word4.value);
      se(word5.value);
      se(word6.value);
   }
};

struct SetResources
{
   static const auto Opcode = Opcode3::SET_RESOURCE;

   latte::Register::Value id;
   gsl::array_view<uint32_t> values;

   template<typename Serialiser>
   void serialise(Serialiser &se)
   {
      se.reg(id, latte::Register::ResourceRegisterBase);
      se(values);
   }
};

struct IndirectBufferCall
{
   static const auto Opcode = Opcode3::INDIRECT_BUFFER_PRIV;
   virtual_ptr<void> addr;
   uint32_t size;

   template<typename Serialiser>
   void serialise(Serialiser &se)
   {
      uint32_t unusedAddrHi = 0;

      se(addr);
      se(unusedAddrHi);
      se(size);
   }
};

struct LoadConfigReg
{
   static const auto Opcode = Opcode3::LOAD_CONFIG_REG;
   virtual_ptr<uint32_t> addr;
   gsl::array_view<std::pair<uint32_t, uint32_t>> values;

   template<typename Serialiser>
   void serialise(Serialiser &se)
   {
      uint32_t unusedAddrHi = 0;

      se(addr);
      se(unusedAddrHi);
      se(values);
   }
};

struct LoadContextReg
{
   static const auto Opcode = Opcode3::LOAD_CONTEXT_REG;
   virtual_ptr<uint32_t> addr;
   gsl::array_view<std::pair<uint32_t, uint32_t>> values;

   template<typename Serialiser>
   void serialise(Serialiser &se)
   {
      uint32_t unusedAddrHi = 0;

      se(addr);
      se(unusedAddrHi);
      se(values);
   }
};

struct LoadAluConst
{
   static const auto Opcode = Opcode3::LOAD_ALU_CONST;
   virtual_ptr<uint32_t> addr;
   gsl::array_view<std::pair<uint32_t, uint32_t>> values;

   template<typename Serialiser>
   void serialise(Serialiser &se)
   {
      uint32_t unusedAddrHi = 0;

      se(addr);
      se(unusedAddrHi);
      se(values);
   }
};

struct LoadLoopConst
{
   static const auto Opcode = Opcode3::LOAD_LOOP_CONST;
   virtual_ptr<uint32_t> addr;
   gsl::array_view<std::pair<uint32_t, uint32_t>> values;

   template<typename Serialiser>
   void serialise(Serialiser &se)
   {
      uint32_t unusedAddrHi = 0;

      se(addr);
      se(unusedAddrHi);
      se(values);
   }
};

struct LoadResource
{
   static const auto Opcode = Opcode3::LOAD_RESOURCE;
   virtual_ptr<uint32_t> addr;
   gsl::array_view<std::pair<uint32_t, uint32_t>> values;

   template<typename Serialiser>
   void serialise(Serialiser &se)
   {
      uint32_t unusedAddrHi = 0;

      se(addr);
      se(unusedAddrHi);
      se(values);
   }
};

struct LoadSampler
{
   static const auto Opcode = Opcode3::LOAD_SAMPLER;
   virtual_ptr<uint32_t> addr;
   gsl::array_view<std::pair<uint32_t, uint32_t>> values;

   template<typename Serialiser>
   void serialise(Serialiser &se)
   {
      uint32_t unusedAddrHi = 0;

      se(addr);
      se(unusedAddrHi);
      se(values);
   }
};

}

#pragma pack(pop)
