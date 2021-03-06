#ifndef ChargeReco_DataFormats_JetChargeLabel_h
#define ChargeReco_DataFormats_JetChargeLabel_h

#include <array>

namespace wbwbx {

class JetChargeLabel {

    public:
        
        int jetIdx;
        
        enum class HadronDecay {
            Electron,
            Muon,
            Tau,
            SingleHadronic, //b-> cX or c-> sX
            DiHadronic, //b->ccX or c-> ssX
            OtherHadronic, //no c or no s
            Undefined //when no b/c hadron is matched
        };
        constexpr static std::array<HadronDecay,7> HadronDecays{{
            HadronDecay::Electron,
            HadronDecay::Muon,
            HadronDecay::Tau,
            HadronDecay::SingleHadronic,
            HadronDecay::DiHadronic,
            HadronDecay::OtherHadronic,
            HadronDecay::Undefined
        }};
        
        int bHadronId;
        int cHadronId;
        
        HadronDecay bHadronDecay;
        HadronDecay cHadronDecay;
        
        int nBHadrons;
        int nCHadrons;
        
        int bHadronCharge; //charge of b quark in hadron (particle level); can differ due to oscillations
        int cHadronCharge;
        int bPartonCharge; //parton-level b quark
        
        int partonFlavor; //generic parton flavour of jet
        int hadronFlavor; //generic hadron flavour of jet
        
        float matchedGenJetDeltaR;
        float matchedGenJetPt;
        
        float matchedBHadronDeltaR;
        float matchedBHadronPt;
        
        float matchedCHadronDeltaR;
        float matchedCHadronPt;
        
        JetChargeLabel():
            bHadronId(0),
            cHadronId(0),
            bHadronDecay(HadronDecay::Undefined),
            cHadronDecay(HadronDecay::Undefined),
            nBHadrons(0),
            nCHadrons(0),
            bHadronCharge(0),
            cHadronCharge(0),
            bPartonCharge(0),
            partonFlavor(0),
            hadronFlavor(0),
            matchedGenJetDeltaR(-1),
            matchedGenJetPt(-1),
            matchedBHadronDeltaR(-1),
            matchedBHadronPt(-1),
            matchedCHadronDeltaR(-1),
            matchedCHadronPt(-1)
        {
        }
        
        
        inline static std::string typeToString(const HadronDecay& hadronDecay)
        {
            switch (hadronDecay)
            {
                case HadronDecay::Electron: return "Electron";
                case HadronDecay::Muon: return "Muon";
                case HadronDecay::Tau: return "Tau";
                case HadronDecay::SingleHadronic: return "SingleHadronic";
                case HadronDecay::DiHadronic: return "DiHadronic";
                case HadronDecay::OtherHadronic: return "OtherHadronic";
                case HadronDecay::Undefined: return "Undefined";
            }
            return "Undefined";
        }
};



}

#endif
