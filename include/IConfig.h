#ifndef __ICONFIG_H__
#define __ICONFIG_H__

static char const * const MATCH_BONUS = 		"match_bonus";
static char const * const MATCH_BONUS_TT = 		"match_bonus_tt";
static char const * const MATCH_BONUS_TC = 		"match_bonus_tc";
static char const * const MISMATCH_PENALTY = 	"mismatch_penalty";
static char const * const GAP_REF_PENALTY = 	"gap_ref_penalty";
static char const * const GAP_READ_PENALTY = 	"gap_read_penalty";
static char const * const GAP_EXTEND_PENALTY = 	"gap_extend_penalty";

static char const * const MODE =			 	"mode";

static char const * const LOCAL =			 	"local";
static char const * const ENDTOEND =		 	"end_to_end";

class IConfig
{
public:

	virtual char const * GetString(char const * const name) const = 0;
	virtual int GetInt(char const * const name) const = 0;
	virtual int GetInt(char const * const name, int min, int max) const = 0;
	virtual int GetParameter(char const * const name) const = 0;
	virtual float GetFloat(char const * const name) const = 0;
	virtual float GetFloat(char const * const name, float min, float max) const = 0;

	virtual int GetIntArray(char const * const name, int * pData, int len) const = 0;
	virtual int GetFloatArray(char const * const name, float * pData, int len) const = 0;
	virtual int GetDoubleArray(char const * const name, double * pData, int len) const = 0;

	virtual bool Exists(char const * const name) const = 0;
	virtual bool HasArray(char const * const name) const = 0;

	virtual ~IConfig() {};
};

typedef void (*pfSetConfig)(IConfig const *);

extern IConfig* _config;
#define Config (*_config)

#endif
