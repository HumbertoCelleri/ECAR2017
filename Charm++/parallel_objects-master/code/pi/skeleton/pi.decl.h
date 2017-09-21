#ifndef _DECL_pi_H_
#define _DECL_pi_H_
#include "charm++.h"
#include "envelope.h"
#include <memory>
#include "sdag.h"
/* DECLS: readonly CProxy_Master mainProxy;
 */

/* DECLS: mainchare Master: Chare{
Master(CkArgMsg* impl_msg);
void addContribution(int numInside, int numTrials);
};
 */
 class Master;
 class CkIndex_Master;
 class CProxy_Master;
/* --------------- index object ------------------ */
class CkIndex_Master:public CkIndex_Chare{
  public:
    typedef Master local_t;
    typedef CkIndex_Master index_t;
    typedef CProxy_Master proxy_t;
    typedef CProxy_Master element_t;

    static int __idx;
    static void __register(const char *s, size_t size);
    /* DECLS: Master(CkArgMsg* impl_msg);
     */
    // Entry point registration at startup
    
    static int reg_Master_CkArgMsg();
    // Entry point index lookup
    
    inline static int idx_Master_CkArgMsg() {
      static int epidx = reg_Master_CkArgMsg();
      return epidx;
    }

    
    static int ckNew(CkArgMsg* impl_msg) { return idx_Master_CkArgMsg(); }
    
    static void _call_Master_CkArgMsg(void* impl_msg, void* impl_obj);
    
    static void _call_sdag_Master_CkArgMsg(void* impl_msg, void* impl_obj);
    /* DECLS: void addContribution(int numInside, int numTrials);
     */
    // Entry point registration at startup
    
    static int reg_addContribution_marshall2();
    // Entry point index lookup
    
    inline static int idx_addContribution_marshall2() {
      static int epidx = reg_addContribution_marshall2();
      return epidx;
    }

    
    inline static int idx_addContribution(void (Master::*)(int numInside, int numTrials) ) {
      return idx_addContribution_marshall2();
    }


    
    static int addContribution(int numInside, int numTrials) { return idx_addContribution_marshall2(); }
    
    static void _call_addContribution_marshall2(void* impl_msg, void* impl_obj);
    
    static void _call_sdag_addContribution_marshall2(void* impl_msg, void* impl_obj);
    
    static int _callmarshall_addContribution_marshall2(char* impl_buf, void* impl_obj_void);
    
    static void _marshallmessagepup_addContribution_marshall2(PUP::er &p,void *msg);
};
/* --------------- element proxy ------------------ */
class CProxy_Master:public CProxy_Chare{
  public:
    typedef Master local_t;
    typedef CkIndex_Master index_t;
    typedef CProxy_Master proxy_t;
    typedef CProxy_Master element_t;

    CProxy_Master(void) {};
    CProxy_Master(CkChareID __cid) : CProxy_Chare(__cid){  }
    CProxy_Master(const Chare *c) : CProxy_Chare(c){  }

    int ckIsDelegated(void) const
    { return CProxy_Chare::ckIsDelegated(); }
    inline CkDelegateMgr *ckDelegatedTo(void) const
    { return CProxy_Chare::ckDelegatedTo(); }
    inline CkDelegateData *ckDelegatedPtr(void) const
    { return CProxy_Chare::ckDelegatedPtr(); }
    CkGroupID ckDelegatedIdx(void) const
    { return CProxy_Chare::ckDelegatedIdx(); }

    inline void ckCheck(void) const
    { CProxy_Chare::ckCheck(); }
    const CkChareID &ckGetChareID(void) const
    { return CProxy_Chare::ckGetChareID(); }
    operator const CkChareID &(void) const
    { return ckGetChareID(); }

    void ckDelegate(CkDelegateMgr *dTo,CkDelegateData *dPtr=NULL)
    {       CProxy_Chare::ckDelegate(dTo,dPtr); }
    void ckUndelegate(void)
    {       CProxy_Chare::ckUndelegate(); }
    void pup(PUP::er &p)
    {       CProxy_Chare::pup(p);
    }

    void ckSetChareID(const CkChareID &c)
    {      CProxy_Chare::ckSetChareID(c); }
    Master *ckLocal(void) const
    { return (Master *)CkLocalChare(&ckGetChareID()); }
/* DECLS: Master(CkArgMsg* impl_msg);
 */
    static CkChareID ckNew(CkArgMsg* impl_msg, int onPE=CK_PE_ANY);
    static void ckNew(CkArgMsg* impl_msg, CkChareID* pcid, int onPE=CK_PE_ANY);
    CProxy_Master(CkArgMsg* impl_msg, int onPE=CK_PE_ANY);

/* DECLS: void addContribution(int numInside, int numTrials);
 */
    
    void addContribution(int numInside, int numTrials, const CkEntryOptions *impl_e_opts=NULL);

};
PUPmarshall(CProxy_Master)
#define Master_SDAG_CODE 
typedef CBaseT1<Chare, CProxy_Master>CBase_Master;

/* DECLS: chare Worker: Chare{
Worker(int numTrials);
};
 */
 class Worker;
 class CkIndex_Worker;
 class CProxy_Worker;
/* --------------- index object ------------------ */
class CkIndex_Worker:public CkIndex_Chare{
  public:
    typedef Worker local_t;
    typedef CkIndex_Worker index_t;
    typedef CProxy_Worker proxy_t;
    typedef CProxy_Worker element_t;

    static int __idx;
    static void __register(const char *s, size_t size);
    /* DECLS: Worker(int numTrials);
     */
    // Entry point registration at startup
    
    static int reg_Worker_marshall1();
    // Entry point index lookup
    
    inline static int idx_Worker_marshall1() {
      static int epidx = reg_Worker_marshall1();
      return epidx;
    }

    
    static int ckNew(int numTrials) { return idx_Worker_marshall1(); }
    
    static void _call_Worker_marshall1(void* impl_msg, void* impl_obj);
    
    static void _call_sdag_Worker_marshall1(void* impl_msg, void* impl_obj);
    
    static int _callmarshall_Worker_marshall1(char* impl_buf, void* impl_obj_void);
    
    static void _marshallmessagepup_Worker_marshall1(PUP::er &p,void *msg);
};
/* --------------- element proxy ------------------ */
class CProxy_Worker:public CProxy_Chare{
  public:
    typedef Worker local_t;
    typedef CkIndex_Worker index_t;
    typedef CProxy_Worker proxy_t;
    typedef CProxy_Worker element_t;

    CProxy_Worker(void) {};
    CProxy_Worker(CkChareID __cid) : CProxy_Chare(__cid){  }
    CProxy_Worker(const Chare *c) : CProxy_Chare(c){  }

    int ckIsDelegated(void) const
    { return CProxy_Chare::ckIsDelegated(); }
    inline CkDelegateMgr *ckDelegatedTo(void) const
    { return CProxy_Chare::ckDelegatedTo(); }
    inline CkDelegateData *ckDelegatedPtr(void) const
    { return CProxy_Chare::ckDelegatedPtr(); }
    CkGroupID ckDelegatedIdx(void) const
    { return CProxy_Chare::ckDelegatedIdx(); }

    inline void ckCheck(void) const
    { CProxy_Chare::ckCheck(); }
    const CkChareID &ckGetChareID(void) const
    { return CProxy_Chare::ckGetChareID(); }
    operator const CkChareID &(void) const
    { return ckGetChareID(); }

    void ckDelegate(CkDelegateMgr *dTo,CkDelegateData *dPtr=NULL)
    {       CProxy_Chare::ckDelegate(dTo,dPtr); }
    void ckUndelegate(void)
    {       CProxy_Chare::ckUndelegate(); }
    void pup(PUP::er &p)
    {       CProxy_Chare::pup(p);
    }

    void ckSetChareID(const CkChareID &c)
    {      CProxy_Chare::ckSetChareID(c); }
    Worker *ckLocal(void) const
    { return (Worker *)CkLocalChare(&ckGetChareID()); }
/* DECLS: Worker(int numTrials);
 */
    static CkChareID ckNew(int numTrials, int onPE=CK_PE_ANY, const CkEntryOptions *impl_e_opts=NULL);
    static void ckNew(int numTrials, CkChareID* pcid, int onPE=CK_PE_ANY, const CkEntryOptions *impl_e_opts=NULL);
    CProxy_Worker(int numTrials, int onPE=CK_PE_ANY, const CkEntryOptions *impl_e_opts=NULL);

};
PUPmarshall(CProxy_Worker)
#define Worker_SDAG_CODE 
typedef CBaseT1<Chare, CProxy_Worker>CBase_Worker;


/* ---------------- method closures -------------- */
class Closure_Master {
  public:


    struct addContribution_2_closure;

};

/* ---------------- method closures -------------- */
class Closure_Worker {
  public:

};

extern void _registerpi(void);
extern "C" void CkRegisterMainModule(void);
#endif
