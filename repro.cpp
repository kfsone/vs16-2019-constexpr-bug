#include <string>
#include <cstdio>

struct Span
{
	using char_type = char16_t;
	using value_type = char_type;
	using ptr_type = const char_type*;

	ptr_type mBegin{};
	ptr_type mEnd{};

	constexpr Span() noexcept = default;
	template<size_t SizeIncNul>
	constexpr Span(const char_type (&literal)[SizeIncNul]) noexcept : mBegin(literal), mEnd(literal + SizeIncNul - 1) {}

	constexpr size_t length() const noexcept { return mEnd - mBegin; }
};

static constexpr Span kHello = u"hello";
static constexpr Span kHash  = u"#";

static_assert(kHello.length() == 5, "expect 'hello' to be 5 characters");
static constexpr size_t kHelloLen = kHello.length();
static_assert(kHash.length() == 1,  "expect '#' to be 1 character");
static constexpr size_t kHashLen = kHash.length();

int main() {
	printf("'hello' length is %zu (kHelloLen=%zu)\n", kHello.length(), kHelloLen);
	printf("'#'     length is %zu (kHashLen=%zu)\n", kHash.length(), kHashLen);
}
