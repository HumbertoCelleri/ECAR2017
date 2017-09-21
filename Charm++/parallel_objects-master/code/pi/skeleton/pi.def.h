
/* ---------------- method closures -------------- */
#ifndef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY

    struct Closure_Master::addContribution_2_closure : public SDAG::Closure {
            int numInside;
            int numTrials;


      addContribution_2_closure() {
        init();
      }
      addContribution_2_closure(CkMigrateMessage*) {
        init();
      }
            int & getP0() { return numInside;}
            int & getP1() { return numTrials;}
      void pup(PUP::er& __p) {
        __p | numInside;
        __p | numTrials;
        packClosure(__p);
      }
      virtual ~addContribution_2_closure() {
      }
      PUPable_decl(SINGLE_ARG(addContribution_2_closure));
    };
#endif /* CK_TEMPLATES_ONLY */


/* ---------------- method closures -------------- */
#ifndef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */


/* DEFS: readonly CProxy_Master mainProxy;
 */
extern CProxy_Master mainProxy;
#ifndef CK_TEMPLATES_ONLY
extern "C" void __xlater_roPup_mainProxy(void *_impl_pup_er) {
  PUP::er &_impl_p=*(PUP::er *)_impl_pup_er;
  _impl_p|mainProxy;
}
#endif /* CK_TEMPLATES_ONLY */

/* DEFS: mainchare Master: Chare{
Master(CkArgMsg* impl_msg);
void addContribution(int numInside, int numTrials);
};
 */
#ifndef CK_TEMPLATES_ONLY
 int CkIndex_Master::__idx=0;
#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
/* DEFS: Master(CkArgMsg* impl_msg);
 */

CkChareID CProxy_Master::ckNew(CkArgMsg* impl_msg, int impl_onPE)
{
  CkChareID impl_ret;
  CkCreateChare(CkIndex_Master::__idx, CkIndex_Master::idx_Master_CkArgMsg(), impl_msg, &impl_ret, impl_onPE);
  return impl_ret;
}

void CProxy_Master::ckNew(CkArgMsg* impl_msg, CkChareID* pcid, int impl_onPE)
{
  CkCreateChare(CkIndex_Master::__idx, CkIndex_Master::idx_Master_CkArgMsg(), impl_msg, pcid, impl_onPE);
}

  CProxy_Master::CProxy_Master(CkArgMsg* impl_msg, int impl_onPE)
{
  CkChareID impl_ret;
  CkCreateChare(CkIndex_Master::__idx, CkIndex_Master::idx_Master_CkArgMsg(), impl_msg, &impl_ret, impl_onPE);
  ckSetChareID(impl_ret);
}

// Entry point registration function

int CkIndex_Master::reg_Master_CkArgMsg() {
  int epidx = CkRegisterEp("Master(CkArgMsg* impl_msg)",
      _call_Master_CkArgMsg, CMessage_CkArgMsg::__idx, __idx, 0);
  CkRegisterMessagePupFn(epidx, (CkMessagePupFn)CkArgMsg::ckDebugPup);
  return epidx;
}


void CkIndex_Master::_call_Master_CkArgMsg(void* impl_msg, void* impl_obj_void)
{
  Master* impl_obj = static_cast<Master *>(impl_obj_void);
  new (impl_obj_void) Master((CkArgMsg*)impl_msg);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void addContribution(int numInside, int numTrials);
 */

void CProxy_Master::addContribution(int numInside, int numTrials, const CkEntryOptions *impl_e_opts)
{
  ckCheck();
  //Marshall: int numInside, int numTrials
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    implP|numInside;
    implP|numTrials;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    implP|numInside;
    implP|numTrials;
  }
  if (ckIsDelegated()) {
    int destPE=CkChareMsgPrep(CkIndex_Master::idx_addContribution_marshall2(), impl_msg, &ckGetChareID());
    if (destPE!=-1) ckDelegatedTo()->ChareSend(ckDelegatedPtr(),CkIndex_Master::idx_addContribution_marshall2(), impl_msg, &ckGetChareID(),destPE);
  } else {
    CkSendMsg(CkIndex_Master::idx_addContribution_marshall2(), impl_msg, &ckGetChareID(),0);
  }
}

// Entry point registration function

int CkIndex_Master::reg_addContribution_marshall2() {
  int epidx = CkRegisterEp("addContribution(int numInside, int numTrials)",
      _call_addContribution_marshall2, CkMarshallMsg::__idx, __idx, 0+CK_EP_NOKEEP);
  CkRegisterMarshallUnpackFn(epidx, _callmarshall_addContribution_marshall2);
  CkRegisterMessagePupFn(epidx, _marshallmessagepup_addContribution_marshall2);

  return epidx;
}


void CkIndex_Master::_call_addContribution_marshall2(void* impl_msg, void* impl_obj_void)
{
  Master* impl_obj = static_cast<Master *>(impl_obj_void);
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  /*Unmarshall pup'd fields: int numInside, int numTrials*/
  PUP::fromMem implP(impl_buf);
  int numInside; implP|numInside;
  int numTrials; implP|numTrials;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  impl_obj->addContribution(numInside, numTrials);
}

int CkIndex_Master::_callmarshall_addContribution_marshall2(char* impl_buf, void* impl_obj_void) {
  Master* impl_obj = static_cast< Master *>(impl_obj_void);
  /*Unmarshall pup'd fields: int numInside, int numTrials*/
  PUP::fromMem implP(impl_buf);
  int numInside; implP|numInside;
  int numTrials; implP|numTrials;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  impl_obj->addContribution(numInside, numTrials);
  return implP.size();
}

void CkIndex_Master::_marshallmessagepup_addContribution_marshall2(PUP::er &implDestP,void *impl_msg) {
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  /*Unmarshall pup'd fields: int numInside, int numTrials*/
  PUP::fromMem implP(impl_buf);
  int numInside; implP|numInside;
  int numTrials; implP|numTrials;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  if (implDestP.hasComments()) implDestP.comment("numInside");
  implDestP|numInside;
  if (implDestP.hasComments()) implDestP.comment("numTrials");
  implDestP|numTrials;
}
PUPable_def(SINGLE_ARG(Closure_Master::addContribution_2_closure))
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
void CkIndex_Master::__register(const char *s, size_t size) {
  __idx = CkRegisterChare(s, size, TypeMainChare);
  CkRegisterBase(__idx, CkIndex_Chare::__idx);
  // REG: Master(CkArgMsg* impl_msg);
  idx_Master_CkArgMsg();
  CkRegisterMainChare(__idx, idx_Master_CkArgMsg());

  // REG: void addContribution(int numInside, int numTrials);
  idx_addContribution_marshall2();

}
#endif /* CK_TEMPLATES_ONLY */

/* DEFS: chare Worker: Chare{
Worker(int numTrials);
};
 */
#ifndef CK_TEMPLATES_ONLY
 int CkIndex_Worker::__idx=0;
#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
/* DEFS: Worker(int numTrials);
 */

CkChareID CProxy_Worker::ckNew(int numTrials, int impl_onPE, const CkEntryOptions *impl_e_opts)
{
  //Marshall: int numTrials
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    implP|numTrials;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    implP|numTrials;
  }
  CkChareID impl_ret;
  CkCreateChare(CkIndex_Worker::__idx, CkIndex_Worker::idx_Worker_marshall1(), impl_msg, &impl_ret, impl_onPE);
  return impl_ret;
}

void CProxy_Worker::ckNew(int numTrials, CkChareID* pcid, int impl_onPE, const CkEntryOptions *impl_e_opts)
{
  //Marshall: int numTrials
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    implP|numTrials;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    implP|numTrials;
  }
  CkCreateChare(CkIndex_Worker::__idx, CkIndex_Worker::idx_Worker_marshall1(), impl_msg, pcid, impl_onPE);
}

  CProxy_Worker::CProxy_Worker(int numTrials, int impl_onPE, const CkEntryOptions *impl_e_opts)
{
  //Marshall: int numTrials
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    implP|numTrials;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    implP|numTrials;
  }
  CkChareID impl_ret;
  CkCreateChare(CkIndex_Worker::__idx, CkIndex_Worker::idx_Worker_marshall1(), impl_msg, &impl_ret, impl_onPE);
  ckSetChareID(impl_ret);
}

// Entry point registration function

int CkIndex_Worker::reg_Worker_marshall1() {
  int epidx = CkRegisterEp("Worker(int numTrials)",
      _call_Worker_marshall1, CkMarshallMsg::__idx, __idx, 0+CK_EP_NOKEEP);
  CkRegisterMarshallUnpackFn(epidx, _callmarshall_Worker_marshall1);
  CkRegisterMessagePupFn(epidx, _marshallmessagepup_Worker_marshall1);

  return epidx;
}


void CkIndex_Worker::_call_Worker_marshall1(void* impl_msg, void* impl_obj_void)
{
  Worker* impl_obj = static_cast<Worker *>(impl_obj_void);
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  /*Unmarshall pup'd fields: int numTrials*/
  PUP::fromMem implP(impl_buf);
  int numTrials; implP|numTrials;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  new (impl_obj_void) Worker(numTrials);
}

int CkIndex_Worker::_callmarshall_Worker_marshall1(char* impl_buf, void* impl_obj_void) {
  Worker* impl_obj = static_cast< Worker *>(impl_obj_void);
  /*Unmarshall pup'd fields: int numTrials*/
  PUP::fromMem implP(impl_buf);
  int numTrials; implP|numTrials;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  new (impl_obj_void) Worker(numTrials);
  return implP.size();
}

void CkIndex_Worker::_marshallmessagepup_Worker_marshall1(PUP::er &implDestP,void *impl_msg) {
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  /*Unmarshall pup'd fields: int numTrials*/
  PUP::fromMem implP(impl_buf);
  int numTrials; implP|numTrials;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  if (implDestP.hasComments()) implDestP.comment("numTrials");
  implDestP|numTrials;
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
void CkIndex_Worker::__register(const char *s, size_t size) {
  __idx = CkRegisterChare(s, size, TypeChare);
  CkRegisterBase(__idx, CkIndex_Chare::__idx);
  // REG: Worker(int numTrials);
  idx_Worker_marshall1();

}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
void _registerpi(void)
{
  static int _done = 0; if(_done) return; _done = 1;
  CkRegisterReadonly("mainProxy","CProxy_Master",sizeof(mainProxy),(void *) &mainProxy,__xlater_roPup_mainProxy);

/* REG: mainchare Master: Chare{
Master(CkArgMsg* impl_msg);
void addContribution(int numInside, int numTrials);
};
*/
  CkIndex_Master::__register("Master", sizeof(Master));

/* REG: chare Worker: Chare{
Worker(int numTrials);
};
*/
  CkIndex_Worker::__register("Worker", sizeof(Worker));

}
extern "C" void CkRegisterMainModule(void) {
  _registerpi();
}
#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
template <>
void CBase_Master::virtual_pup(PUP::er &p) {
    recursive_pup<Master >(dynamic_cast<Master* >(this), p);
}
#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
template <>
void CBase_Worker::virtual_pup(PUP::er &p) {
    recursive_pup<Worker >(dynamic_cast<Worker* >(this), p);
}
#endif /* CK_TEMPLATES_ONLY */
