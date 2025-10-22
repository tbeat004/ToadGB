#pragma once
#include <cstdint>

class Cpu {
public:
    // 8-bit registers
    uint8_t A = 0, F = 0; // F: bits 3..0 must be 0
    uint8_t B = 0, C = 0;
    uint8_t D = 0, E = 0;
    uint8_t H = 0, L = 0;

    // Special 16-bit
    uint16_t SP = 0;
    uint16_t PC = 0;

    // 16-bit views (pairs)
    uint16_t AF() const { return (uint16_t(A) << 8) | (F & 0xF0); }
    void setAF(uint16_t v) { A = uint8_t(v >> 8); F = uint8_t(v & 0xF0); } // mask low nibble

    uint16_t BC() const { return (uint16_t(B) << 8) | C; }
    void setBC(uint16_t v) { B = uint8_t(v >> 8); C = uint8_t(v); }

    uint16_t DE() const { return (uint16_t(D) << 8) | E; }
    void setDE(uint16_t v) { D = uint8_t(v >> 8); E = uint8_t(v); }

    uint16_t HL() const { return (uint16_t(H) << 8) | L; }
    void setHL(uint16_t v) { H = uint8_t(v >> 8); L = uint8_t(v); }

    // Flags
    enum : uint8_t { ZF = 0x80, NF = 0x40, HF = 0x20, CF = 0x10 };
    void setFlag(uint8_t m, bool on) { F = on ? uint8_t((F | m) & 0xF0) : uint8_t((F & ~m) & 0xF0); }
    bool flag(uint8_t m) const { return (F & m) != 0; }
};