[@bs.deriving jsConverter]
type types = [
  | [@bs.as "application/1d-interleaved-parityfec"]
    `application_1dinterleavedparityfec
  | [@bs.as "application/3gpdash-qoe-report+xml"]
    `application_3gpdashqoereportxml
  | [@bs.as "application/3gpp-ims+xml"] `application_3gppimsxml
  | [@bs.as "application/A2L"] `application_A2L
  | [@bs.as "application/activemessage"] `application_activemessage
  | [@bs.as "application/activemessage"] `application_activemessage
  | [@bs.as "application/activity+json"] `application_activityjson
  | [@bs.as "application/alto-costmap+json"] `application_altocostmapjson
  | [@bs.as "application/alto-costmapfilter+json"]
    `application_altocostmapfilterjson
  | [@bs.as "application/alto-directory+json"] `application_altodirectoryjson
  | [@bs.as "application/alto-endpointprop+json"]
    `application_altoendpointpropjson
  | [@bs.as "application/alto-endpointpropparams+json"]
    `application_altoendpointpropparamsjson
  | [@bs.as "application/alto-endpointcost+json"]
    `application_altoendpointcostjson
  | [@bs.as "application/alto-endpointcostparams+json"]
    `application_altoendpointcostparamsjson
  | [@bs.as "application/alto-error+json"] `application_altoerrorjson
  | [@bs.as "application/alto-networkmapfilter+json"]
    `application_altonetworkmapfilterjson
  | [@bs.as "application/alto-networkmap+json"] `application_altonetworkmapjson
  | [@bs.as "application/AML"] `application_AML
  | [@bs.as "application/andrew-inset"] `application_andrewinset
  | [@bs.as "application/applefile"] `application_applefile
  | [@bs.as "application/ATF"] `application_ATF
  | [@bs.as "application/ATFX"] `application_ATFX
  | [@bs.as "application/atom+xml"] `application_atomxml
  | [@bs.as "application/atomcat+xml"] `application_atomcatxml
  | [@bs.as "application/atomdeleted+xml"] `application_atomdeletedxml
  | [@bs.as "application/atomicmail"] `application_atomicmail
  | [@bs.as "application/atomsvc+xml"] `application_atomsvcxml
  | [@bs.as "application/ATXML"] `application_ATXML
  | [@bs.as "application/auth-policy+xml"] `application_authpolicyxml
  | [@bs.as "application/bacnet-xdd+zip"] `application_bacnetxddzip
  | [@bs.as "application/batch-SMTP"] `application_batchSMTP
  | [@bs.as "application/beep+xml"] `application_beepxml
  | [@bs.as "application/calendar+json"] `application_calendarjson
  | [@bs.as "application/calendar+xml"] `application_calendarxml
  | [@bs.as "application/call-completion"] `application_callcompletion
  | [@bs.as "application/CALS-1840"] `application_CALS1840
  | [@bs.as "application/cbor"] `application_cbor
  | [@bs.as "application/cccex"] `application_cccex
  | [@bs.as "application/ccmp+xml"] `application_ccmpxml
  | [@bs.as "application/ccxml+xml"] `application_ccxmlxml
  | [@bs.as "application/CDFX+XML"] `application_CDFXXML
  | [@bs.as "application/cdmi-capability"] `application_cdmicapability
  | [@bs.as "application/cdmi-container"] `application_cdmicontainer
  | [@bs.as "application/cdmi-domain"] `application_cdmidomain
  | [@bs.as "application/cdmi-object"] `application_cdmiobject
  | [@bs.as "application/cdmi-queue"] `application_cdmiqueue
  | [@bs.as "application/cdni"] `application_cdni
  | [@bs.as "application/CEA"] `application_CEA
  | [@bs.as "application/cea-2018+xml"] `application_cea2018xml
  | [@bs.as "application/cellml+xml"] `application_cellmlxml
  | [@bs.as "application/cfw"] `application_cfw
  | [@bs.as "application/clue_info+xml"] `application_clue_infoxml
  | [@bs.as "application/cms"] `application_cms
  | [@bs.as "application/cnrp+xml"] `application_cnrpxml
  | [@bs.as "application/coap-group+json"] `application_coapgroupjson
  | [@bs.as "application/coap-payload"] `application_coappayload
  | [@bs.as "application/commonground"] `application_commonground
  | [@bs.as "application/conference-info+xml"] `application_conferenceinfoxml
  | [@bs.as "application/cpl+xml"] `application_cplxml
  | [@bs.as "application/cose"] `application_cose
  | [@bs.as "application/cose-key"] `application_cosekey
  | [@bs.as "application/cose-key-set"] `application_cosekeyset
  | [@bs.as "application/csrattrs"] `application_csrattrs
  | [@bs.as "application/csta+xml"] `application_cstaxml
  | [@bs.as "application/CSTAdata+xml"] `application_CSTAdataxml
  | [@bs.as "application/csvm+json"] `application_csvmjson
  | [@bs.as "application/cwt"] `application_cwt
  | [@bs.as "application/cybercash"] `application_cybercash
  | [@bs.as "application/dash+xml"] `application_dashxml
  | [@bs.as "application/dashdelta"] `application_dashdelta
  | [@bs.as "application/davmount+xml"] `application_davmountxml
  | [@bs.as "application/dca-rft"] `application_dcarft
  | [@bs.as "application/DCD"] `application_DCD
  | [@bs.as "application/dec-dx"] `application_decdx
  | [@bs.as "application/dialog-info+xml"] `application_dialoginfoxml
  | [@bs.as "application/dicom"] `application_dicom
  | [@bs.as "application/dicom+json"] `application_dicomjson
  | [@bs.as "application/dicom+xml"] `application_dicomxml
  | [@bs.as "application/DII"] `application_DII
  | [@bs.as "application/DIT"] `application_DIT
  | [@bs.as "application/dns"] `application_dns
  | [@bs.as "application/dskpp+xml"] `application_dskppxml
  | [@bs.as "application/dssc+der"] `application_dsscder
  | [@bs.as "application/dssc+xml"] `application_dsscxml
  | [@bs.as "application/dvcs"] `application_dvcs
  | [@bs.as "application/ecmascript"] `application_ecmascript
  | [@bs.as "application/EDI-consent"] `application_EDIconsent
  | [@bs.as "application/EDIFACT"] `application_EDIFACT
  | [@bs.as "application/EDI-X12"] `application_EDIX12
  | [@bs.as "application/efi"] `application_efi
  | [@bs.as "application/EmergencyCallData.Comment+xml"]
    `application_EmergencyCallDataCommentxml
  | [@bs.as "application/EmergencyCallData.Control+xml"]
    `application_EmergencyCallDataControlxml
  | [@bs.as "application/EmergencyCallData.DeviceInfo+xml"]
    `application_EmergencyCallDataDeviceInfoxml
  | [@bs.as "application/EmergencyCallData.eCall.MSD"]
    `application_EmergencyCallDataeCallMSD
  | [@bs.as "application/EmergencyCallData.ProviderInfo+xml"]
    `application_EmergencyCallDataProviderInfoxml
  | [@bs.as "application/EmergencyCallData.ServiceInfo+xml"]
    `application_EmergencyCallDataServiceInfoxml
  | [@bs.as "application/EmergencyCallData.SubscriberInfo+xml"]
    `application_EmergencyCallDataSubscriberInfoxml
  | [@bs.as "application/EmergencyCallData.VEDS+xml"]
    `application_EmergencyCallDataVEDSxml
  | [@bs.as "application/emotionml+xml"] `application_emotionmlxml
  | [@bs.as "application/encaprtp"] `application_encaprtp
  | [@bs.as "application/epp+xml"] `application_eppxml
  | [@bs.as "application/epub+zip"] `application_epubzip
  | [@bs.as "application/eshop"] `application_eshop
  | [@bs.as "application/example"] `application_example
  | [@bs.as "application/fastinfoset"] `application_fastinfoset
  | [@bs.as "application/fastsoap"] `application_fastsoap
  | [@bs.as "application/fdt+xml"] `application_fdtxml
  | [@bs.as "application/fhir+json"] `application_fhirjson
  | [@bs.as "application/fhir+xml"] `application_fhirxml
  | [@bs.as "application/fits"] `application_fits
  | [@bs.as "application/font-sfnt"] `application_fontsfnt
  | [@bs.as "application/font-tdpfr"] `application_fonttdpfr
  | [@bs.as "application/font-woff"] `application_fontwoff
  | [@bs.as "application/framework-attributes+xml"]
    `application_frameworkattributesxml
  | [@bs.as "application/geo+json"] `application_geojson
  | [@bs.as "application/geo+json-seq"] `application_geojsonseq
  | [@bs.as "application/geoxacml+xml"] `application_geoxacmlxml
  | [@bs.as "application/gltf-buffer"] `application_gltfbuffer
  | [@bs.as "application/gml+xml"] `application_gmlxml
  | [@bs.as "application/gzip"] `application_gzip
  | [@bs.as "application/H224"] `application_H224
  | [@bs.as "application/held+xml"] `application_heldxml
  | [@bs.as "application/http"] `application_http
  | [@bs.as "application/hyperstudio"] `application_hyperstudio
  | [@bs.as "application/ibe-key-request+xml"] `application_ibekeyrequestxml
  | [@bs.as "application/ibe-pkg-reply+xml"] `application_ibepkgreplyxml
  | [@bs.as "application/ibe-pp-data"] `application_ibeppdata
  | [@bs.as "application/iges"] `application_iges
  | [@bs.as "application/im-iscomposing+xml"] `application_imiscomposingxml
  | [@bs.as "application/index"] `application_index
  | [@bs.as "application/index.cmd"] `application_indexcmd
  | [@bs.as "application/index-obj"] `application_indexobj
  | [@bs.as "application/index.response"] `application_indexresponse
  | [@bs.as "application/index.vnd"] `application_indexvnd
  | [@bs.as "application/inkml+xml"] `application_inkmlxml
  | [@bs.as "application/IOTP"] `application_IOTP
  | [@bs.as "application/ipfix"] `application_ipfix
  | [@bs.as "application/ipp"] `application_ipp
  | [@bs.as "application/ISUP"] `application_ISUP
  | [@bs.as "application/its+xml"] `application_itsxml
  | [@bs.as "application/javascript"] `application_javascript
  | [@bs.as "application/jf2feed+json"] `application_jf2feedjson
  | [@bs.as "application/jose"] `application_jose
  | [@bs.as "application/jose+json"] `application_josejson
  | [@bs.as "application/jrd+json"] `application_jrdjson
  | [@bs.as "application/json"] `application_json
  | [@bs.as "application/json-patch+json"] `application_jsonpatchjson
  | [@bs.as "application/json-seq"] `application_jsonseq
  | [@bs.as "application/jwk+json"] `application_jwkjson
  | [@bs.as "application/jwk-set+json"] `application_jwksetjson
  | [@bs.as "application/jwt"] `application_jwt
  | [@bs.as "application/kpml-request+xml"] `application_kpmlrequestxml
  | [@bs.as "application/kpml-response+xml"] `application_kpmlresponsexml
  | [@bs.as "application/ld+json"] `application_ldjson
  | [@bs.as "application/lgr+xml"] `application_lgrxml
  | [@bs.as "application/link-format"] `application_linkformat
  | [@bs.as "application/load-control+xml"] `application_loadcontrolxml
  | [@bs.as "application/lost+xml"] `application_lostxml
  | [@bs.as "application/lostsync+xml"] `application_lostsyncxml
  | [@bs.as "application/LXF"] `application_LXF
  | [@bs.as "application/mac-binhex40"] `application_macbinhex40
  | [@bs.as "application/macwriteii"] `application_macwriteii
  | [@bs.as "application/mads+xml"] `application_madsxml
  | [@bs.as "application/marc"] `application_marc
  | [@bs.as "application/marcxml+xml"] `application_marcxmlxml
  | [@bs.as "application/mathematica"] `application_mathematica
  | [@bs.as "application/mbms-associated-procedure-description+xml"]
    `application_mbmsassociatedproceduredescriptionxml
  | [@bs.as "application/mbms-deregister+xml"] `application_mbmsderegisterxml
  | [@bs.as "application/mbms-envelope+xml"] `application_mbmsenvelopexml
  | [@bs.as "application/mbms-msk-response+xml"]
    `application_mbmsmskresponsexml
  | [@bs.as "application/mbms-msk+xml"] `application_mbmsmskxml
  | [@bs.as "application/mbms-protection-description+xml"]
    `application_mbmsprotectiondescriptionxml
  | [@bs.as "application/mbms-reception-report+xml"]
    `application_mbmsreceptionreportxml
  | [@bs.as "application/mbms-register-response+xml"]
    `application_mbmsregisterresponsexml
  | [@bs.as "application/mbms-register+xml"] `application_mbmsregisterxml
  | [@bs.as "application/mbms-schedule+xml"] `application_mbmsschedulexml
  | [@bs.as "application/mbms-user-service-description+xml"]
    `application_mbmsuserservicedescriptionxml
  | [@bs.as "application/mbox"] `application_mbox
  | [@bs.as "application/media_control+xml"] `application_media_controlxml
  | [@bs.as "application/media-policy-dataset+xml"]
    `application_mediapolicydatasetxml
  | [@bs.as "application/mediaservercontrol+xml"]
    `application_mediaservercontrolxml
  | [@bs.as "application/merge-patch+json"] `application_mergepatchjson
  | [@bs.as "application/metalink4+xml"] `application_metalink4xml
  | [@bs.as "application/mets+xml"] `application_metsxml
  | [@bs.as "application/MF4"] `application_MF4
  | [@bs.as "application/mikey"] `application_mikey
  | [@bs.as "application/mmt-usd+xml"] `application_mmtusdxml
  | [@bs.as "application/mods+xml"] `application_modsxml
  | [@bs.as "application/moss-keys"] `application_mosskeys
  | [@bs.as "application/moss-signature"] `application_mosssignature
  | [@bs.as "application/mosskey-data"] `application_mosskeydata
  | [@bs.as "application/mosskey-request"] `application_mosskeyrequest
  | [@bs.as "application/mp21"] `application_mp21
  | [@bs.as "application/mp4"] `application_mp4
  | [@bs.as "application/mpeg4-generic"] `application_mpeg4generic
  | [@bs.as "application/mpeg4-iod"] `application_mpeg4iod
  | [@bs.as "application/mpeg4-iod-xmt"] `application_mpeg4iodxmt
  | [@bs.as "application/mrb-consumer+xml"] `application_mrbconsumerxml
  | [@bs.as "application/mrb-publish+xml"] `application_mrbpublishxml
  | [@bs.as "application/msc-ivr+xml"] `application_mscivrxml
  | [@bs.as "application/msc-mixer+xml"] `application_mscmixerxml
  | [@bs.as "application/msword"] `application_msword
  | [@bs.as "application/mxf"] `application_mxf
  | [@bs.as "application/n-quads"] `application_nquads
  | [@bs.as "application/n-triples"] `application_ntriples
  | [@bs.as "application/nasdata"] `application_nasdata
  | [@bs.as "application/news-checkgroups"] `application_newscheckgroups
  | [@bs.as "application/news-groupinfo"] `application_newsgroupinfo
  | [@bs.as "application/news-transmission"] `application_newstransmission
  | [@bs.as "application/nlsml+xml"] `application_nlsmlxml
  | [@bs.as "application/node"] `application_node
  | [@bs.as "application/nss"] `application_nss
  | [@bs.as "application/ocsp-request"] `application_ocsprequest
  | [@bs.as "application/ocsp-response"] `application_ocspresponse
  | [@bs.as "application/octet-stream"] `application_octetstream
  | [@bs.as "application/ODA"] `application_ODA
  | [@bs.as "application/ODX"] `application_ODX
  | [@bs.as "application/oebps-package+xml"] `application_oebpspackagexml
  | [@bs.as "application/ogg"] `application_ogg
  | [@bs.as "application/oxps"] `application_oxps
  | [@bs.as "application/p2p-overlay+xml"] `application_p2poverlayxml
  | [@bs.as "application/passport"] `application_passport
  | [@bs.as "application/patch-ops-error+xml"] `application_patchopserrorxml
  | [@bs.as "application/pdf"] `application_pdf
  | [@bs.as "application/PDX"] `application_PDX
  | [@bs.as "application/pgp-encrypted"] `application_pgpencrypted
  | [@bs.as "application/pgp-signature"] `application_pgpsignature
  | [@bs.as "application/pidf-diff+xml"] `application_pidfdiffxml
  | [@bs.as "application/pidf+xml"] `application_pidfxml
  | [@bs.as "application/pkcs10"] `application_pkcs10
  | [@bs.as "application/pkcs7-mime"] `application_pkcs7mime
  | [@bs.as "application/pkcs7-signature"] `application_pkcs7signature
  | [@bs.as "application/pkcs8"] `application_pkcs8
  | [@bs.as "application/pkcs8-encrypted"] `application_pkcs8encrypted
  | [@bs.as "application/pkcs12"] `application_pkcs12
  | [@bs.as "application/pkix-attr-cert"] `application_pkixattrcert
  | [@bs.as "application/pkix-cert"] `application_pkixcert
  | [@bs.as "application/pkix-crl"] `application_pkixcrl
  | [@bs.as "application/pkix-pkipath"] `application_pkixpkipath
  | [@bs.as "application/pkixcmp"] `application_pkixcmp
  | [@bs.as "application/pls+xml"] `application_plsxml
  | [@bs.as "application/poc-settings+xml"] `application_pocsettingsxml
  | [@bs.as "application/postscript"] `application_postscript
  | [@bs.as "application/ppsp-tracker+json"] `application_ppsptrackerjson
  | [@bs.as "application/problem+json"] `application_problemjson
  | [@bs.as "application/problem+xml"] `application_problemxml
  | [@bs.as "application/provenance+xml"] `application_provenancexml
  | [@bs.as "application/prs.alvestrand.titrax-sheet"]
    `application_prsalvestrandtitraxsheet
  | [@bs.as "application/prs.cww"] `application_prscww
  | [@bs.as "application/prs.hpub+zip"] `application_prshpubzip
  | [@bs.as "application/prs.nprend"] `application_prsnprend
  | [@bs.as "application/prs.plucker"] `application_prsplucker
  | [@bs.as "application/prs.rdf-xml-crypt"] `application_prsrdfxmlcrypt
  | [@bs.as "application/prs.xsf+xml"] `application_prsxsfxml
  | [@bs.as "application/pskc+xml"] `application_pskcxml
  | [@bs.as "application/rdf+xml"] `application_rdfxml
  | [@bs.as "application/route-apd+xml"] `application_routeapdxml
  | [@bs.as "application/route-s-tsid+xml"] `application_routestsidxml
  | [@bs.as "application/route-usd+xml"] `application_routeusdxml
  | [@bs.as "application/QSIG"] `application_QSIG
  | [@bs.as "application/raptorfec"] `application_raptorfec
  | [@bs.as "application/rdap+json"] `application_rdapjson
  | [@bs.as "application/reginfo+xml"] `application_reginfoxml
  | [@bs.as "application/relax-ng-compact-syntax"]
    `application_relaxngcompactsyntax
  | [@bs.as "application/remote-printing"] `application_remoteprinting
  | [@bs.as "application/reputon+json"] `application_reputonjson
  | [@bs.as "application/resource-lists-diff+xml"]
    `application_resourcelistsdiffxml
  | [@bs.as "application/resource-lists+xml"] `application_resourcelistsxml
  | [@bs.as "application/rfc+xml"] `application_rfcxml
  | [@bs.as "application/riscos"] `application_riscos
  | [@bs.as "application/rlmi+xml"] `application_rlmixml
  | [@bs.as "application/rls-services+xml"] `application_rlsservicesxml
  | [@bs.as "application/rpki-ghostbusters"] `application_rpkighostbusters
  | [@bs.as "application/rpki-manifest"] `application_rpkimanifest
  | [@bs.as "application/rpki-publication"] `application_rpkipublication
  | [@bs.as "application/rpki-roa"] `application_rpkiroa
  | [@bs.as "application/rpki-updown"] `application_rpkiupdown
  | [@bs.as "application/rtf"] `application_rtf
  | [@bs.as "application/rtploopback"] `application_rtploopback
  | [@bs.as "application/rtx"] `application_rtx
  | [@bs.as "application/samlassertion+xml"] `application_samlassertionxml
  | [@bs.as "application/samlmetadata+xml"] `application_samlmetadataxml
  | [@bs.as "application/sbml+xml"] `application_sbmlxml
  | [@bs.as "application/scaip+xml"] `application_scaipxml
  | [@bs.as "application/scim+json"] `application_scimjson
  | [@bs.as "application/scvp-cv-request"] `application_scvpcvrequest
  | [@bs.as "application/scvp-cv-response"] `application_scvpcvresponse
  | [@bs.as "application/scvp-vp-request"] `application_scvpvprequest
  | [@bs.as "application/scvp-vp-response"] `application_scvpvpresponse
  | [@bs.as "application/sdp"] `application_sdp
  | [@bs.as "application/sep-exi"] `application_sepexi
  | [@bs.as "application/sep+xml"] `application_sepxml
  | [@bs.as "application/session-info"] `application_sessioninfo
  | [@bs.as "application/set-payment"] `application_setpayment
  | [@bs.as "application/set-payment-initiation"]
    `application_setpaymentinitiation
  | [@bs.as "application/set-registration"] `application_setregistration
  | [@bs.as "application/set-registration-initiation"]
    `application_setregistrationinitiation
  | [@bs.as "application/SGML"] `application_SGML
  | [@bs.as "application/sgml-open-catalog"] `application_sgmlopencatalog
  | [@bs.as "application/shf+xml"] `application_shfxml
  | [@bs.as "application/sieve"] `application_sieve
  | [@bs.as "application/simple-filter+xml"] `application_simplefilterxml
  | [@bs.as "application/simple-message-summary"]
    `application_simplemessagesummary
  | [@bs.as "application/simpleSymbolContainer"]
    `application_simpleSymbolContainer
  | [@bs.as "application/slate"] `application_slate
  | [@bs.as "application/smil"] `application_smil
  | [@bs.as "application/smil+xml"] `application_smilxml
  | [@bs.as "application/smpte336m"] `application_smpte336m
  | [@bs.as "application/soap+fastinfoset"] `application_soapfastinfoset
  | [@bs.as "application/soap+xml"] `application_soapxml
  | [@bs.as "application/spirits-event+xml"] `application_spiritseventxml
  | [@bs.as "application/sql"] `application_sql
  | [@bs.as "application/srgs"] `application_srgs
  | [@bs.as "application/srgs+xml"] `application_srgsxml
  | [@bs.as "application/sru+xml"] `application_sruxml
  | [@bs.as "application/ssml+xml"] `application_ssmlxml
  | [@bs.as "application/tamp-apex-update"] `application_tampapexupdate
  | [@bs.as "application/tamp-apex-update-confirm"]
    `application_tampapexupdateconfirm
  | [@bs.as "application/tamp-community-update"]
    `application_tampcommunityupdate
  | [@bs.as "application/tamp-community-update-confirm"]
    `application_tampcommunityupdateconfirm
  | [@bs.as "application/tamp-error"] `application_tamperror
  | [@bs.as "application/tamp-sequence-adjust"] `application_tampsequenceadjust
  | [@bs.as "application/tamp-sequence-adjust-confirm"]
    `application_tampsequenceadjustconfirm
  | [@bs.as "application/tamp-status-query"] `application_tampstatusquery
  | [@bs.as "application/tamp-status-response"] `application_tampstatusresponse
  | [@bs.as "application/tamp-update"] `application_tampupdate
  | [@bs.as "application/tamp-update-confirm"] `application_tampupdateconfirm
  | [@bs.as "application/tei+xml"] `application_teixml
  | [@bs.as "application/thraud+xml"] `application_thraudxml
  | [@bs.as "application/timestamp-query"] `application_timestampquery
  | [@bs.as "application/timestamp-reply"] `application_timestampreply
  | [@bs.as "application/timestamped-data"] `application_timestampeddata
  | [@bs.as "application/tnauthlist"] `application_tnauthlist
  | [@bs.as "application/trig"] `application_trig
  | [@bs.as "application/ttml+xml"] `application_ttmlxml
  | [@bs.as "application/tve-trigger"] `application_tvetrigger
  | [@bs.as "application/ulpfec"] `application_ulpfec
  | [@bs.as "application/urc-grpsheet+xml"] `application_urcgrpsheetxml
  | [@bs.as "application/urc-ressheet+xml"] `application_urcressheetxml
  | [@bs.as "application/urc-targetdesc+xml"] `application_urctargetdescxml
  | [@bs.as "application/urc-uisocketdesc+xml"] `application_urcuisocketdescxml
  | [@bs.as "application/vcard+json"] `application_vcardjson
  | [@bs.as "application/vcard+xml"] `application_vcardxml
  | [@bs.as "application/vemmi"] `application_vemmi
  | [@bs.as "application/vnd.1000minds.decision-model+xml"]
    `application_vnd1000mindsdecisionmodelxml
  | [@bs.as "application/vnd.3gpp.access-transfer-events+xml"]
    `application_vnd3gppaccesstransfereventsxml
  | [@bs.as "application/vnd.3gpp.bsf+xml"] `application_vnd3gppbsfxml
  | [@bs.as "application/vnd.3gpp.GMOP+xml"] `application_vnd3gppGMOPxml
  | [@bs.as "application/vnd.3gpp.mcptt-affiliation-command+xml"]
    `application_vnd3gppmcpttaffiliationcommandxml
  | [@bs.as "application/vnd.3gpp.mcptt-floor-request+xml"]
    `application_vnd3gppmcpttfloorrequestxml
  | [@bs.as "application/vnd.3gpp.mcptt-info+xml"]
    `application_vnd3gppmcpttinfoxml
  | [@bs.as "application/vnd.3gpp.mcptt-location-info+xml"]
    `application_vnd3gppmcpttlocationinfoxml
  | [@bs.as "application/vnd.3gpp.mcptt-mbms-usage-info+xml"]
    `application_vnd3gppmcpttmbmsusageinfoxml
  | [@bs.as "application/vnd.3gpp.mcptt-signed+xml"]
    `application_vnd3gppmcpttsignedxml
  | [@bs.as "application/vnd.3gpp.mid-call+xml"] `application_vnd3gppmidcallxml
  | [@bs.as "application/vnd.3gpp.pic-bw-large"] `application_vnd3gpppicbwlarge
  | [@bs.as "application/vnd.3gpp.pic-bw-small"] `application_vnd3gpppicbwsmall
  | [@bs.as "application/vnd.3gpp.pic-bw-var"] `application_vnd3gpppicbwvar
  | [@bs.as "application/vnd.3gpp-prose-pc3ch+xml"]
    `application_vnd3gppprosepc3chxml
  | [@bs.as "application/vnd.3gpp-prose+xml"] `application_vnd3gppprosexml
  | [@bs.as "application/vnd.3gpp.sms"] `application_vnd3gppsms
  | [@bs.as "application/vnd.3gpp.sms+xml"] `application_vnd3gppsmsxml
  | [@bs.as "application/vnd.3gpp.srvcc-ext+xml"]
    `application_vnd3gppsrvccextxml
  | [@bs.as "application/vnd.3gpp.SRVCC-info+xml"]
    `application_vnd3gppSRVCCinfoxml
  | [@bs.as "application/vnd.3gpp.state-and-event-info+xml"]
    `application_vnd3gppstateandeventinfoxml
  | [@bs.as "application/vnd.3gpp.ussd+xml"] `application_vnd3gppussdxml
  | [@bs.as "application/vnd.3gpp-v2x-local-service-information"]
    `application_vnd3gppv2xlocalserviceinformation
  | [@bs.as "application/vnd.3gpp2.bcmcsinfo+xml"]
    `application_vnd3gpp2bcmcsinfoxml
  | [@bs.as "application/vnd.3gpp2.sms"] `application_vnd3gpp2sms
  | [@bs.as "application/vnd.3gpp2.tcap"] `application_vnd3gpp2tcap
  | [@bs.as "application/vnd.3lightssoftware.imagescal"]
    `application_vnd3lightssoftwareimagescal
  | [@bs.as "application/vnd.3M.Post-it-Notes"] `application_vnd3MPostitNotes
  | [@bs.as "application/vnd.accpac.simply.aso"]
    `application_vndaccpacsimplyaso
  | [@bs.as "application/vnd.accpac.simply.imp"]
    `application_vndaccpacsimplyimp
  | [@bs.as "application/vnd-acucobol"] `application_vndacucobol
  | [@bs.as "application/vnd.acucorp"] `application_vndacucorp
  | [@bs.as "application/vnd.adobe.flash-movie"]
    `application_vndadobeflashmovie
  | [@bs.as "application/vnd.adobe.formscentral.fcdt"]
    `application_vndadobeformscentralfcdt
  | [@bs.as "application/vnd.adobe.fxp"] `application_vndadobefxp
  | [@bs.as "application/vnd.adobe.partial-upload"]
    `application_vndadobepartialupload
  | [@bs.as "application/vnd.adobe.xdp+xml"] `application_vndadobexdpxml
  | [@bs.as "application/vnd.adobe.xfdf"] `application_vndadobexfdf
  | [@bs.as "application/vnd.aether.imp"] `application_vndaetherimp
  | [@bs.as "application/vnd.afpc.afplinedata"] `application_vndafpcafplinedata
  | [@bs.as "application/vnd.afpc.modca"] `application_vndafpcmodca
  | [@bs.as "application/vnd.ah-barcode"] `application_vndahbarcode
  | [@bs.as "application/vnd.ahead.space"] `application_vndaheadspace
  | [@bs.as "application/vnd.airzip.filesecure.azf"]
    `application_vndairzipfilesecureazf
  | [@bs.as "application/vnd.airzip.filesecure.azs"]
    `application_vndairzipfilesecureazs
  | [@bs.as "application/vnd.amadeus+json"] `application_vndamadeusjson
  | [@bs.as "application/vnd.amazon.mobi8-ebook"]
    `application_vndamazonmobi8ebook
  | [@bs.as "application/vnd.americandynamics.acc"]
    `application_vndamericandynamicsacc
  | [@bs.as "application/vnd.amiga.ami"] `application_vndamigaami
  | [@bs.as "application/vnd.amundsen.maze+xml"]
    `application_vndamundsenmazexml
  | [@bs.as "application/vnd.anki"] `application_vndanki
  | [@bs.as "application/vnd.anser-web-certificate-issue-initiation"]
    `application_vndanserwebcertificateissueinitiation
  | [@bs.as "application/vnd.antix.game-component"]
    `application_vndantixgamecomponent
  | [@bs.as "application/vnd.apache.thrift.binary"]
    `application_vndapachethriftbinary
  | [@bs.as "application/vnd.apache.thrift.compact"]
    `application_vndapachethriftcompact
  | [@bs.as "application/vnd.apache.thrift.json"]
    `application_vndapachethriftjson
  | [@bs.as "application/vnd.api+json"] `application_vndapijson
  | [@bs.as "application/vnd.apothekende.reservation+json"]
    `application_vndapothekendereservationjson
  | [@bs.as "application/vnd.apple.mpegurl"] `application_vndapplempegurl
  | [@bs.as "application/vnd.apple.installer+xml"]
    `application_vndappleinstallerxml
  | [@bs.as "application/vnd.arastra.swi"] `application_vndarastraswi
  | [@bs.as "application/vnd.aristanetworks.swi"]
    `application_vndaristanetworksswi
  | [@bs.as "application/vnd.artisan+json"] `application_vndartisanjson
  | [@bs.as "application/vnd.artsquare"] `application_vndartsquare
  | [@bs.as "application/vnd.astraea-software.iota"]
    `application_vndastraeasoftwareiota
  | [@bs.as "application/vnd.audiograph"] `application_vndaudiograph
  | [@bs.as "application/vnd.autopackage"] `application_vndautopackage
  | [@bs.as "application/vnd.avalon+json"] `application_vndavalonjson
  | [@bs.as "application/vnd.avistar+xml"] `application_vndavistarxml
  | [@bs.as "application/vnd.balsamiq.bmml+xml"]
    `application_vndbalsamiqbmmlxml
  | [@bs.as "application/vnd.bbf.usp.msg"] `application_vndbbfuspmsg
  | [@bs.as "application/vnd.bbf.usp.msg+json"] `application_vndbbfuspmsgjson
  | [@bs.as "application/vnd.balsamiq.bmpr"] `application_vndbalsamiqbmpr
  | [@bs.as "application/vnd.bekitzur-stech+json"]
    `application_vndbekitzurstechjson
  | [@bs.as "application/vnd.bint.med-content"] `application_vndbintmedcontent
  | [@bs.as "application/vnd.biopax.rdf+xml"] `application_vndbiopaxrdfxml
  | [@bs.as "application/vnd.blink-idb-value-wrapper"]
    `application_vndblinkidbvaluewrapper
  | [@bs.as "application/vnd.blueice.multipass"]
    `application_vndblueicemultipass
  | [@bs.as "application/vnd.bluetooth.ep.oob"] `application_vndbluetoothepoob
  | [@bs.as "application/vnd.bluetooth.le.oob"] `application_vndbluetoothleoob
  | [@bs.as "application/vnd.bmi"] `application_vndbmi
  | [@bs.as "application/vnd.businessobjects"] `application_vndbusinessobjects
  | [@bs.as "application/vnd.cab-jscript"] `application_vndcabjscript
  | [@bs.as "application/vnd.canon-cpdl"] `application_vndcanoncpdl
  | [@bs.as "application/vnd.canon-lips"] `application_vndcanonlips
  | [@bs.as "application/vnd.capasystems-pg+json"]
    `application_vndcapasystemspgjson
  | [@bs.as "application/vnd.cendio.thinlinc.clientconf"]
    `application_vndcendiothinlincclientconf
  | [@bs.as "application/vnd.century-systems.tcp_stream"]
    `application_vndcenturysystemstcp_stream
  | [@bs.as "application/vnd.chemdraw+xml"] `application_vndchemdrawxml
  | [@bs.as "application/vnd.chess-pgn"] `application_vndchesspgn
  | [@bs.as "application/vnd.chipnuts.karaoke-mmd"]
    `application_vndchipnutskaraokemmd
  | [@bs.as "application/vnd.cinderella"] `application_vndcinderella
  | [@bs.as "application/vnd.cirpack.isdn-ext"] `application_vndcirpackisdnext
  | [@bs.as "application/vnd.citationstyles.style+xml"]
    `application_vndcitationstylesstylexml
  | [@bs.as "application/vnd.claymore"] `application_vndclaymore
  | [@bs.as "application/vnd.cloanto.rp9"] `application_vndcloantorp9
  | [@bs.as "application/vnd.clonk.c4group"] `application_vndclonkc4group
  | [@bs.as "application/vnd.cluetrust.cartomobile-config"]
    `application_vndcluetrustcartomobileconfig
  | [@bs.as "application/vnd.cluetrust.cartomobile-config-pkg"]
    `application_vndcluetrustcartomobileconfigpkg
  | [@bs.as "application/vnd.coffeescript"] `application_vndcoffeescript
  | [@bs.as "application/vnd.collabio.xodocuments.document"]
    `application_vndcollabioxodocumentsdocument
  | [@bs.as "application/vnd.collabio.xodocuments.document-template"]
    `application_vndcollabioxodocumentsdocumenttemplate
  | [@bs.as "application/vnd.collabio.xodocuments.presentation"]
    `application_vndcollabioxodocumentspresentation
  | [@bs.as "application/vnd.collabio.xodocuments.presentation-template"]
    `application_vndcollabioxodocumentspresentationtemplate
  | [@bs.as "application/vnd.collabio.xodocuments.spreadsheet"]
    `application_vndcollabioxodocumentsspreadsheet
  | [@bs.as "application/vnd.collabio.xodocuments.spreadsheet-template"]
    `application_vndcollabioxodocumentsspreadsheettemplate
  | [@bs.as "application/vnd.collection.doc+json"]
    `application_vndcollectiondocjson
  | [@bs.as "application/vnd.collection+json"] `application_vndcollectionjson
  | [@bs.as "application/vnd.collection.next+json"]
    `application_vndcollectionnextjson
  | [@bs.as "application/vnd.comicbook-rar"] `application_vndcomicbookrar
  | [@bs.as "application/vnd.comicbook+zip"] `application_vndcomicbookzip
  | [@bs.as "application/vnd.commerce-battelle"]
    `application_vndcommercebattelle
  | [@bs.as "application/vnd.commonspace"] `application_vndcommonspace
  | [@bs.as "application/vnd.coreos.ignition+json"]
    `application_vndcoreosignitionjson
  | [@bs.as "application/vnd.cosmocaller"] `application_vndcosmocaller
  | [@bs.as "application/vnd.contact.cmsg"] `application_vndcontactcmsg
  | [@bs.as "application/vnd.crick.clicker"] `application_vndcrickclicker
  | [@bs.as "application/vnd.crick.clicker.keyboard"]
    `application_vndcrickclickerkeyboard
  | [@bs.as "application/vnd.crick.clicker.palette"]
    `application_vndcrickclickerpalette
  | [@bs.as "application/vnd.crick.clicker.template"]
    `application_vndcrickclickertemplate
  | [@bs.as "application/vnd.crick.clicker.wordbank"]
    `application_vndcrickclickerwordbank
  | [@bs.as "application/vnd.criticaltools.wbs+xml"]
    `application_vndcriticaltoolswbsxml
  | [@bs.as "application/vnd.ctc-posml"] `application_vndctcposml
  | [@bs.as "application/vnd.ctct.ws+xml"] `application_vndctctwsxml
  | [@bs.as "application/vnd.cups-pdf"] `application_vndcupspdf
  | [@bs.as "application/vnd.cups-postscript"] `application_vndcupspostscript
  | [@bs.as "application/vnd.cups-ppd"] `application_vndcupsppd
  | [@bs.as "application/vnd.cups-raster"] `application_vndcupsraster
  | [@bs.as "application/vnd.cups-raw"] `application_vndcupsraw
  | [@bs.as "application/vnd-curl"] `application_vndcurl
  | [@bs.as "application/vnd.cyan.dean.root+xml"]
    `application_vndcyandeanrootxml
  | [@bs.as "application/vnd.cybank"] `application_vndcybank
  | [@bs.as "application/vnd.d2l.coursepackage1p0+zip"]
    `application_vndd2lcoursepackage1p0zip
  | [@bs.as "application/vnd-dart"] `application_vnddart
  | [@bs.as "application/vnd.data-vision.rdz"] `application_vnddatavisionrdz
  | [@bs.as "application/vnd.datapackage+json"] `application_vnddatapackagejson
  | [@bs.as "application/vnd.dataresource+json"]
    `application_vnddataresourcejson
  | [@bs.as "application/vnd.debian.binary-package"]
    `application_vnddebianbinarypackage
  | [@bs.as "application/vnd.dece.data"] `application_vnddecedata
  | [@bs.as "application/vnd.dece.ttml+xml"] `application_vnddecettmlxml
  | [@bs.as "application/vnd.dece.unspecified"] `application_vnddeceunspecified
  | [@bs.as "application/vnd.dece-zip"] `application_vnddecezip
  | [@bs.as "application/vnd.denovo.fcselayout-link"]
    `application_vnddenovofcselayoutlink
  | [@bs.as "application/vnd.desmume-movie"] `application_vnddesmumemovie
  | [@bs.as "application/vnd.dir-bi.plate-dl-nosuffix"]
    `application_vnddirbiplatedlnosuffix
  | [@bs.as "application/vnd.dm.delegation+xml"]
    `application_vnddmdelegationxml
  | [@bs.as "application/vnd.dna"] `application_vnddna
  | [@bs.as "application/vnd.document+json"] `application_vnddocumentjson
  | [@bs.as "application/vnd.dolby.mobile.1"] `application_vnddolbymobile1
  | [@bs.as "application/vnd.dolby.mobile.2"] `application_vnddolbymobile2
  | [@bs.as "application/vnd.doremir.scorecloud-binary-document"]
    `application_vnddoremirscorecloudbinarydocument
  | [@bs.as "application/vnd.dpgraph"] `application_vnddpgraph
  | [@bs.as "application/vnd.dreamfactory"] `application_vnddreamfactory
  | [@bs.as "application/vnd.drive+json"] `application_vnddrivejson
  | [@bs.as "application/vnd.dtg.local"] `application_vnddtglocal
  | [@bs.as "application/vnd.dtg.local.flash"] `application_vnddtglocalflash
  | [@bs.as "application/vnd.dtg.local-html"] `application_vnddtglocalhtml
  | [@bs.as "application/vnd.dvb.ait"] `application_vnddvbait
  | [@bs.as "application/vnd.dvb.dvbj"] `application_vnddvbdvbj
  | [@bs.as "application/vnd.dvb.esgcontainer"] `application_vnddvbesgcontainer
  | [@bs.as "application/vnd.dvb.ipdcdftnotifaccess"]
    `application_vnddvbipdcdftnotifaccess
  | [@bs.as "application/vnd.dvb.ipdcesgaccess"]
    `application_vnddvbipdcesgaccess
  | [@bs.as "application/vnd.dvb.ipdcesgaccess2"]
    `application_vnddvbipdcesgaccess2
  | [@bs.as "application/vnd.dvb.ipdcesgpdd"] `application_vnddvbipdcesgpdd
  | [@bs.as "application/vnd.dvb.ipdcroaming"] `application_vnddvbipdcroaming
  | [@bs.as "application/vnd.dvb.iptv.alfec-base"]
    `application_vnddvbiptvalfecbase
  | [@bs.as "application/vnd.dvb.iptv.alfec-enhancement"]
    `application_vnddvbiptvalfecenhancement
  | [@bs.as "application/vnd.dvb.notif-aggregate-root+xml"]
    `application_vnddvbnotifaggregaterootxml
  | [@bs.as "application/vnd.dvb.notif-container+xml"]
    `application_vnddvbnotifcontainerxml
  | [@bs.as "application/vnd.dvb.notif-generic+xml"]
    `application_vnddvbnotifgenericxml
  | [@bs.as "application/vnd.dvb.notif-ia-msglist+xml"]
    `application_vnddvbnotifiamsglistxml
  | [@bs.as "application/vnd.dvb.notif-ia-registration-request+xml"]
    `application_vnddvbnotifiaregistrationrequestxml
  | [@bs.as "application/vnd.dvb.notif-ia-registration-response+xml"]
    `application_vnddvbnotifiaregistrationresponsexml
  | [@bs.as "application/vnd.dvb.notif-init+xml"]
    `application_vnddvbnotifinitxml
  | [@bs.as "application/vnd.dvb.pfr"] `application_vnddvbpfr
  | [@bs.as "application/vnd.dvb_service"] `application_vnddvb_service
  | [@bs.as "application/vnd-dxr"] `application_vnddxr
  | [@bs.as "application/vnd.dynageo"] `application_vnddynageo
  | [@bs.as "application/vnd.dzr"] `application_vnddzr
  | [@bs.as "application/vnd.easykaraoke.cdgdownload"]
    `application_vndeasykaraokecdgdownload
  | [@bs.as "application/vnd.ecip.rlp"] `application_vndeciprlp
  | [@bs.as "application/vnd.ecdis-update"] `application_vndecdisupdate
  | [@bs.as "application/vnd.ecowin.chart"] `application_vndecowinchart
  | [@bs.as "application/vnd.ecowin.filerequest"]
    `application_vndecowinfilerequest
  | [@bs.as "application/vnd.ecowin.fileupdate"]
    `application_vndecowinfileupdate
  | [@bs.as "application/vnd.ecowin.series"] `application_vndecowinseries
  | [@bs.as "application/vnd.ecowin.seriesrequest"]
    `application_vndecowinseriesrequest
  | [@bs.as "application/vnd.ecowin.seriesupdate"]
    `application_vndecowinseriesupdate
  | [@bs.as "application/vnd.efi-img"] `application_vndefiimg
  | [@bs.as "application/vnd.efi-iso"] `application_vndefiiso
  | [@bs.as "application/vnd.emclient.accessrequest+xml"]
    `application_vndemclientaccessrequestxml
  | [@bs.as "application/vnd.enliven"] `application_vndenliven
  | [@bs.as "application/vnd.enphase.envoy"] `application_vndenphaseenvoy
  | [@bs.as "application/vnd.eprints.data+xml"] `application_vndeprintsdataxml
  | [@bs.as "application/vnd.epson.esf"] `application_vndepsonesf
  | [@bs.as "application/vnd.epson.msf"] `application_vndepsonmsf
  | [@bs.as "application/vnd.epson.quickanime"] `application_vndepsonquickanime
  | [@bs.as "application/vnd.epson.salt"] `application_vndepsonsalt
  | [@bs.as "application/vnd.epson.ssf"] `application_vndepsonssf
  | [@bs.as "application/vnd.ericsson.quickcall"]
    `application_vndericssonquickcall
  | [@bs.as "application/vnd.espass-espass+zip"]
    `application_vndespassespasszip
  | [@bs.as "application/vnd.eszigno3+xml"] `application_vndeszigno3xml
  | [@bs.as "application/vnd.etsi.aoc+xml"] `application_vndetsiaocxml
  | [@bs.as "application/vnd.etsi.asic-s+zip"] `application_vndetsiasicszip
  | [@bs.as "application/vnd.etsi.asic-e+zip"] `application_vndetsiasicezip
  | [@bs.as "application/vnd.etsi.cug+xml"] `application_vndetsicugxml
  | [@bs.as "application/vnd.etsi.iptvcommand+xml"]
    `application_vndetsiiptvcommandxml
  | [@bs.as "application/vnd.etsi.iptvdiscovery+xml"]
    `application_vndetsiiptvdiscoveryxml
  | [@bs.as "application/vnd.etsi.iptvprofile+xml"]
    `application_vndetsiiptvprofilexml
  | [@bs.as "application/vnd.etsi.iptvsad-bc+xml"]
    `application_vndetsiiptvsadbcxml
  | [@bs.as "application/vnd.etsi.iptvsad-cod+xml"]
    `application_vndetsiiptvsadcodxml
  | [@bs.as "application/vnd.etsi.iptvsad-npvr+xml"]
    `application_vndetsiiptvsadnpvrxml
  | [@bs.as "application/vnd.etsi.iptvservice+xml"]
    `application_vndetsiiptvservicexml
  | [@bs.as "application/vnd.etsi.iptvsync+xml"]
    `application_vndetsiiptvsyncxml
  | [@bs.as "application/vnd.etsi.iptvueprofile+xml"]
    `application_vndetsiiptvueprofilexml
  | [@bs.as "application/vnd.etsi.mcid+xml"] `application_vndetsimcidxml
  | [@bs.as "application/vnd.etsi.mheg5"] `application_vndetsimheg5
  | [@bs.as "application/vnd.etsi.overload-control-policy-dataset+xml"]
    `application_vndetsioverloadcontrolpolicydatasetxml
  | [@bs.as "application/vnd.etsi.pstn+xml"] `application_vndetsipstnxml
  | [@bs.as "application/vnd.etsi.sci+xml"] `application_vndetsiscixml
  | [@bs.as "application/vnd.etsi.simservs+xml"]
    `application_vndetsisimservsxml
  | [@bs.as "application/vnd.etsi.timestamp-token"]
    `application_vndetsitimestamptoken
  | [@bs.as "application/vnd.etsi.tsl+xml"] `application_vndetsitslxml
  | [@bs.as "application/vnd.etsi.tsl.der"] `application_vndetsitslder
  | [@bs.as "application/vnd.evolv.ecig.profile"]
    `application_vndevolvecigprofile
  | [@bs.as "application/vnd.evolv.ecig.settings"]
    `application_vndevolvecigsettings
  | [@bs.as "application/vnd.evolv.ecig.theme"] `application_vndevolvecigtheme
  | [@bs.as "application/vnd.eudora.data"] `application_vndeudoradata
  | [@bs.as "application/vnd.ezpix-album"] `application_vndezpixalbum
  | [@bs.as "application/vnd.ezpix-package"] `application_vndezpixpackage
  | [@bs.as "application/vnd.f-secure.mobile"] `application_vndfsecuremobile
  | [@bs.as "application/vnd.fastcopy-disk-image"]
    `application_vndfastcopydiskimage
  | [@bs.as "application/vnd-fdf"] `application_vndfdf
  | [@bs.as "application/vnd.fdsn.mseed"] `application_vndfdsnmseed
  | [@bs.as "application/vnd.fdsn.seed"] `application_vndfdsnseed
  | [@bs.as "application/vnd.ffsns"] `application_vndffsns
  | [@bs.as "application/vnd.filmit.zfc"] `application_vndfilmitzfc
  | [@bs.as "application/vnd.fints"] `application_vndfints
  | [@bs.as "application/vnd.firemonkeys.cloudcell"]
    `application_vndfiremonkeyscloudcell
  | [@bs.as "application/vnd.FloGraphIt"] `application_vndFloGraphIt
  | [@bs.as "application/vnd.fluxtime.clip"] `application_vndfluxtimeclip
  | [@bs.as "application/vnd.font-fontforge-sfd"]
    `application_vndfontfontforgesfd
  | [@bs.as "application/vnd.framemaker"] `application_vndframemaker
  | [@bs.as "application/vnd.frogans.fnc"] `application_vndfrogansfnc
  | [@bs.as "application/vnd.frogans.ltf"] `application_vndfrogansltf
  | [@bs.as "application/vnd.fsc.weblaunch"] `application_vndfscweblaunch
  | [@bs.as "application/vnd.fujitsu.oasys"] `application_vndfujitsuoasys
  | [@bs.as "application/vnd.fujitsu.oasys2"] `application_vndfujitsuoasys2
  | [@bs.as "application/vnd.fujitsu.oasys3"] `application_vndfujitsuoasys3
  | [@bs.as "application/vnd.fujitsu.oasysgp"] `application_vndfujitsuoasysgp
  | [@bs.as "application/vnd.fujitsu.oasysprs"] `application_vndfujitsuoasysprs
  | [@bs.as "application/vnd.fujixerox.ART4"] `application_vndfujixeroxART4
  | [@bs.as "application/vnd.fujixerox.ART-EX"] `application_vndfujixeroxARTEX
  | [@bs.as "application/vnd.fujixerox.ddd"] `application_vndfujixeroxddd
  | [@bs.as "application/vnd.fujixerox.docuworks"]
    `application_vndfujixeroxdocuworks
  | [@bs.as "application/vnd.fujixerox.docuworks.binder"]
    `application_vndfujixeroxdocuworksbinder
  | [@bs.as "application/vnd.fujixerox.docuworks.container"]
    `application_vndfujixeroxdocuworkscontainer
  | [@bs.as "application/vnd.fujixerox.HBPL"] `application_vndfujixeroxHBPL
  | [@bs.as "application/vnd.fut-misnet"] `application_vndfutmisnet
  | [@bs.as "application/vnd.fuzzysheet"] `application_vndfuzzysheet
  | [@bs.as "application/vnd.genomatix.tuxedo"] `application_vndgenomatixtuxedo
  | [@bs.as "application/vnd.geo+json"] `application_vndgeojson
  | [@bs.as "application/vnd.geocube+xml"] `application_vndgeocubexml
  | [@bs.as "application/vnd.geogebra.file"] `application_vndgeogebrafile
  | [@bs.as "application/vnd.geogebra.tool"] `application_vndgeogebratool
  | [@bs.as "application/vnd.geometry-explorer"]
    `application_vndgeometryexplorer
  | [@bs.as "application/vnd.geonext"] `application_vndgeonext
  | [@bs.as "application/vnd.geoplan"] `application_vndgeoplan
  | [@bs.as "application/vnd.geospace"] `application_vndgeospace
  | [@bs.as "application/vnd.gerber"] `application_vndgerber
  | [@bs.as "application/vnd.globalplatform.card-content-mgt"]
    `application_vndglobalplatformcardcontentmgt
  | [@bs.as "application/vnd.globalplatform.card-content-mgt-response"]
    `application_vndglobalplatformcardcontentmgtresponse
  | [@bs.as "application/vnd.gmx"] `application_vndgmx
  | [@bs.as "application/vnd.google-earth.kml+xml"]
    `application_vndgoogleearthkmlxml
  | [@bs.as "application/vnd.google-earth.kmz"] `application_vndgoogleearthkmz
  | [@bs.as "application/vnd.gov.sk.e-form+xml"] `application_vndgovskeformxml
  | [@bs.as "application/vnd.gov.sk.e-form+zip"] `application_vndgovskeformzip
  | [@bs.as "application/vnd.gov.sk.xmldatacontainer+xml"]
    `application_vndgovskxmldatacontainerxml
  | [@bs.as "application/vnd.grafeq"] `application_vndgrafeq
  | [@bs.as "application/vnd.gridmp"] `application_vndgridmp
  | [@bs.as "application/vnd.groove-account"] `application_vndgrooveaccount
  | [@bs.as "application/vnd.groove-help"] `application_vndgroovehelp
  | [@bs.as "application/vnd.groove-identity-message"]
    `application_vndgrooveidentitymessage
  | [@bs.as "application/vnd.groove-injector"] `application_vndgrooveinjector
  | [@bs.as "application/vnd.groove-tool-message"]
    `application_vndgroovetoolmessage
  | [@bs.as "application/vnd.groove-tool-template"]
    `application_vndgroovetooltemplate
  | [@bs.as "application/vnd.groove-vcard"] `application_vndgroovevcard
  | [@bs.as "application/vnd.hal+json"] `application_vndhaljson
  | [@bs.as "application/vnd.hal+xml"] `application_vndhalxml
  | [@bs.as "application/vnd.HandHeld-Entertainment+xml"]
    `application_vndHandHeldEntertainmentxml
  | [@bs.as "application/vnd.hbci"] `application_vndhbci
  | [@bs.as "application/vnd.hc+json"] `application_vndhcjson
  | [@bs.as "application/vnd.hcl-bireports"] `application_vndhclbireports
  | [@bs.as "application/vnd.hdt"] `application_vndhdt
  | [@bs.as "application/vnd.heroku+json"] `application_vndherokujson
  | [@bs.as "application/vnd.hhe.lesson-player"]
    `application_vndhhelessonplayer
  | [@bs.as "application/vnd.hp-HPGL"] `application_vndhpHPGL
  | [@bs.as "application/vnd.hp-hpid"] `application_vndhphpid
  | [@bs.as "application/vnd.hp-hps"] `application_vndhphps
  | [@bs.as "application/vnd.hp-jlyt"] `application_vndhpjlyt
  | [@bs.as "application/vnd.hp-PCL"] `application_vndhpPCL
  | [@bs.as "application/vnd.hp-PCLXL"] `application_vndhpPCLXL
  | [@bs.as "application/vnd.httphone"] `application_vndhttphone
  | [@bs.as "application/vnd.hydrostatix.sof-data"]
    `application_vndhydrostatixsofdata
  | [@bs.as "application/vnd.hyper-item+json"] `application_vndhyperitemjson
  | [@bs.as "application/vnd.hyper+json"] `application_vndhyperjson
  | [@bs.as "application/vnd.hyperdrive+json"] `application_vndhyperdrivejson
  | [@bs.as "application/vnd.hzn-3d-crossword"] `application_vndhzn3dcrossword
  | [@bs.as "application/vnd.ibm.afplinedata"] `application_vndibmafplinedata
  | [@bs.as "application/vnd.ibm.electronic-media"]
    `application_vndibmelectronicmedia
  | [@bs.as "application/vnd.ibm.MiniPay"] `application_vndibmMiniPay
  | [@bs.as "application/vnd.ibm.modcap"] `application_vndibmmodcap
  | [@bs.as "application/vnd.ibm.rights-management"]
    `application_vndibmrightsmanagement
  | [@bs.as "application/vnd.ibm.secure-container"]
    `application_vndibmsecurecontainer
  | [@bs.as "application/vnd.iccprofile"] `application_vndiccprofile
  | [@bs.as "application/vnd.ieee.1905"] `application_vndieee1905
  | [@bs.as "application/vnd.igloader"] `application_vndigloader
  | [@bs.as "application/vnd.imagemeter.folder+zip"]
    `application_vndimagemeterfolderzip
  | [@bs.as "application/vnd.imagemeter.image+zip"]
    `application_vndimagemeterimagezip
  | [@bs.as "application/vnd.immervision-ivp"] `application_vndimmervisionivp
  | [@bs.as "application/vnd.immervision-ivu"] `application_vndimmervisionivu
  | [@bs.as "application/vnd.ims.imsccv1p1"] `application_vndimsimsccv1p1
  | [@bs.as "application/vnd.ims.imsccv1p2"] `application_vndimsimsccv1p2
  | [@bs.as "application/vnd.ims.imsccv1p3"] `application_vndimsimsccv1p3
  | [@bs.as "application/vnd.ims.lis.v2.result+json"]
    `application_vndimslisv2resultjson
  | [@bs.as "application/vnd.ims.lti.v2.toolconsumerprofile+json"]
    `application_vndimsltiv2toolconsumerprofilejson
  | [@bs.as "application/vnd.ims.lti.v2.toolproxy.id+json"]
    `application_vndimsltiv2toolproxyidjson
  | [@bs.as "application/vnd.ims.lti.v2.toolproxy+json"]
    `application_vndimsltiv2toolproxyjson
  | [@bs.as "application/vnd.ims.lti.v2.toolsettings+json"]
    `application_vndimsltiv2toolsettingsjson
  | [@bs.as "application/vnd.ims.lti.v2.toolsettings.simple+json"]
    `application_vndimsltiv2toolsettingssimplejson
  | [@bs.as "application/vnd.informedcontrol.rms+xml"]
    `application_vndinformedcontrolrmsxml
  | [@bs.as "application/vnd.infotech.project"] `application_vndinfotechproject
  | [@bs.as "application/vnd.infotech.project+xml"]
    `application_vndinfotechprojectxml
  | [@bs.as "application/vnd.informix-visionary"]
    `application_vndinformixvisionary
  | [@bs.as "application/vnd.innopath.wamp.notification"]
    `application_vndinnopathwampnotification
  | [@bs.as "application/vnd.insors.igm"] `application_vndinsorsigm
  | [@bs.as "application/vnd.intercon.formnet"] `application_vndinterconformnet
  | [@bs.as "application/vnd.intergeo"] `application_vndintergeo
  | [@bs.as "application/vnd.intertrust.digibox"]
    `application_vndintertrustdigibox
  | [@bs.as "application/vnd.intertrust.nncp"] `application_vndintertrustnncp
  | [@bs.as "application/vnd.intu.qbo"] `application_vndintuqbo
  | [@bs.as "application/vnd.intu.qfx"] `application_vndintuqfx
  | [@bs.as "application/vnd.iptc.g2.catalogitem+xml"]
    `application_vndiptcg2catalogitemxml
  | [@bs.as "application/vnd.iptc.g2.conceptitem+xml"]
    `application_vndiptcg2conceptitemxml
  | [@bs.as "application/vnd.iptc.g2.knowledgeitem+xml"]
    `application_vndiptcg2knowledgeitemxml
  | [@bs.as "application/vnd.iptc.g2.newsitem+xml"]
    `application_vndiptcg2newsitemxml
  | [@bs.as "application/vnd.iptc.g2.newsmessage+xml"]
    `application_vndiptcg2newsmessagexml
  | [@bs.as "application/vnd.iptc.g2.packageitem+xml"]
    `application_vndiptcg2packageitemxml
  | [@bs.as "application/vnd.iptc.g2.planningitem+xml"]
    `application_vndiptcg2planningitemxml
  | [@bs.as "application/vnd.ipunplugged.rcprofile"]
    `application_vndipunpluggedrcprofile
  | [@bs.as "application/vnd.irepository.package+xml"]
    `application_vndirepositorypackagexml
  | [@bs.as "application/vnd.is-xpr"] `application_vndisxpr
  | [@bs.as "application/vnd.isac.fcs"] `application_vndisacfcs
  | [@bs.as "application/vnd.jam"] `application_vndjam
  | [@bs.as "application/vnd.japannet-directory-service"]
    `application_vndjapannetdirectoryservice
  | [@bs.as "application/vnd.japannet-jpnstore-wakeup"]
    `application_vndjapannetjpnstorewakeup
  | [@bs.as "application/vnd.japannet-payment-wakeup"]
    `application_vndjapannetpaymentwakeup
  | [@bs.as "application/vnd.japannet-registration"]
    `application_vndjapannetregistration
  | [@bs.as "application/vnd.japannet-registration-wakeup"]
    `application_vndjapannetregistrationwakeup
  | [@bs.as "application/vnd.japannet-setstore-wakeup"]
    `application_vndjapannetsetstorewakeup
  | [@bs.as "application/vnd.japannet-verification"]
    `application_vndjapannetverification
  | [@bs.as "application/vnd.japannet-verification-wakeup"]
    `application_vndjapannetverificationwakeup
  | [@bs.as "application/vnd.jcp.javame.midlet-rms"]
    `application_vndjcpjavamemidletrms
  | [@bs.as "application/vnd.jisp"] `application_vndjisp
  | [@bs.as "application/vnd.joost.joda-archive"]
    `application_vndjoostjodaarchive
  | [@bs.as "application/vnd.jsk.isdn-ngn"] `application_vndjskisdnngn
  | [@bs.as "application/vnd.kahootz"] `application_vndkahootz
  | [@bs.as "application/vnd.kde.karbon"] `application_vndkdekarbon
  | [@bs.as "application/vnd.kde.kchart"] `application_vndkdekchart
  | [@bs.as "application/vnd.kde.kformula"] `application_vndkdekformula
  | [@bs.as "application/vnd.kde.kivio"] `application_vndkdekivio
  | [@bs.as "application/vnd.kde.kontour"] `application_vndkdekontour
  | [@bs.as "application/vnd.kde.kpresenter"] `application_vndkdekpresenter
  | [@bs.as "application/vnd.kde.kspread"] `application_vndkdekspread
  | [@bs.as "application/vnd.kde.kword"] `application_vndkdekword
  | [@bs.as "application/vnd.kenameaapp"] `application_vndkenameaapp
  | [@bs.as "application/vnd.kidspiration"] `application_vndkidspiration
  | [@bs.as "application/vnd.Kinar"] `application_vndKinar
  | [@bs.as "application/vnd.koan"] `application_vndkoan
  | [@bs.as "application/vnd.kodak-descriptor"] `application_vndkodakdescriptor
  | [@bs.as "application/vnd.las.las+json"] `application_vndlaslasjson
  | [@bs.as "application/vnd.las.las+xml"] `application_vndlaslasxml
  | [@bs.as "application/vnd.liberty-request+xml"]
    `application_vndlibertyrequestxml
  | [@bs.as "application/vnd.llamagraphics.life-balance.desktop"]
    `application_vndllamagraphicslifebalancedesktop
  | [@bs.as "application/vnd.llamagraphics.life-balance.exchange+xml"]
    `application_vndllamagraphicslifebalanceexchangexml
  | [@bs.as "application/vnd.lotus-1-2-3"] `application_vndlotus123
  | [@bs.as "application/vnd.lotus-approach"] `application_vndlotusapproach
  | [@bs.as "application/vnd.lotus-freelance"] `application_vndlotusfreelance
  | [@bs.as "application/vnd.lotus-notes"] `application_vndlotusnotes
  | [@bs.as "application/vnd.lotus-organizer"] `application_vndlotusorganizer
  | [@bs.as "application/vnd.lotus-screencam"] `application_vndlotusscreencam
  | [@bs.as "application/vnd.lotus-wordpro"] `application_vndlotuswordpro
  | [@bs.as "application/vnd.macports.portpkg"] `application_vndmacportsportpkg
  | [@bs.as "application/vnd.macports.portpkg"] `application_vndmacportsportpkg
  | [@bs.as "application/vnd.mapbox-vector-tile"]
    `application_vndmapboxvectortile
  | [@bs.as "application/vnd.marlin.drm.actiontoken+xml"]
    `application_vndmarlindrmactiontokenxml
  | [@bs.as "application/vnd.marlin.drm.conftoken+xml"]
    `application_vndmarlindrmconftokenxml
  | [@bs.as "application/vnd.marlin.drm.license+xml"]
    `application_vndmarlindrmlicensexml
  | [@bs.as "application/vnd.marlin.drm.mdcf"] `application_vndmarlindrmmdcf
  | [@bs.as "application/vnd.mason+json"] `application_vndmasonjson
  | [@bs.as "application/vnd.maxmind.maxmind-db"]
    `application_vndmaxmindmaxminddb
  | [@bs.as "application/vnd.mcd"] `application_vndmcd
  | [@bs.as "application/vnd.medcalcdata"] `application_vndmedcalcdata
  | [@bs.as "application/vnd.mediastation.cdkey"]
    `application_vndmediastationcdkey
  | [@bs.as "application/vnd.meridian-slingshot"]
    `application_vndmeridianslingshot
  | [@bs.as "application/vnd.MFER"] `application_vndMFER
  | [@bs.as "application/vnd.mfmp"] `application_vndmfmp
  | [@bs.as "application/vnd.micro+json"] `application_vndmicrojson
  | [@bs.as "application/vnd.micrografx.flo"] `application_vndmicrografxflo
  | [@bs.as "application/vnd.micrografx-igx"] `application_vndmicrografxigx
  | [@bs.as "application/vnd.microsoft.portable-executable"]
    `application_vndmicrosoftportableexecutable
  | [@bs.as "application/vnd.microsoft.windows.thumbnail-cache"]
    `application_vndmicrosoftwindowsthumbnailcache
  | [@bs.as "application/vnd.miele+json"] `application_vndmielejson
  | [@bs.as "application/vnd-mif"] `application_vndmif
  | [@bs.as "application/vnd.minisoft-hp3000-save"]
    `application_vndminisofthp3000save
  | [@bs.as "application/vnd.mitsubishi.misty-guard.trustweb"]
    `application_vndmitsubishimistyguardtrustweb
  | [@bs.as "application/vnd.Mobius.DAF"] `application_vndMobiusDAF
  | [@bs.as "application/vnd.Mobius.DIS"] `application_vndMobiusDIS
  | [@bs.as "application/vnd.Mobius.MBK"] `application_vndMobiusMBK
  | [@bs.as "application/vnd.Mobius.MQY"] `application_vndMobiusMQY
  | [@bs.as "application/vnd.Mobius.MSL"] `application_vndMobiusMSL
  | [@bs.as "application/vnd.Mobius.PLC"] `application_vndMobiusPLC
  | [@bs.as "application/vnd.Mobius.TXF"] `application_vndMobiusTXF
  | [@bs.as "application/vnd.mophun.application"]
    `application_vndmophunapplication
  | [@bs.as "application/vnd.mophun.certificate"]
    `application_vndmophuncertificate
  | [@bs.as "application/vnd.motorola.flexsuite"]
    `application_vndmotorolaflexsuite
  | [@bs.as "application/vnd.motorola.flexsuite.adsi"]
    `application_vndmotorolaflexsuiteadsi
  | [@bs.as "application/vnd.motorola.flexsuite.fis"]
    `application_vndmotorolaflexsuitefis
  | [@bs.as "application/vnd.motorola.flexsuite.gotap"]
    `application_vndmotorolaflexsuitegotap
  | [@bs.as "application/vnd.motorola.flexsuite.kmr"]
    `application_vndmotorolaflexsuitekmr
  | [@bs.as "application/vnd.motorola.flexsuite.ttc"]
    `application_vndmotorolaflexsuitettc
  | [@bs.as "application/vnd.motorola.flexsuite.wem"]
    `application_vndmotorolaflexsuitewem
  | [@bs.as "application/vnd.motorola.iprm"] `application_vndmotorolaiprm
  | [@bs.as "application/vnd.mozilla.xul+xml"] `application_vndmozillaxulxml
  | [@bs.as "application/vnd.ms-artgalry"] `application_vndmsartgalry
  | [@bs.as "application/vnd.ms-asf"] `application_vndmsasf
  | [@bs.as "application/vnd.ms-cab-compressed"]
    `application_vndmscabcompressed
  | [@bs.as "application/vnd.ms-3mfdocument"] `application_vndms3mfdocument
  | [@bs.as "application/vnd.ms-excel"] `application_vndmsexcel
  | [@bs.as "application/vnd.ms-excel.addin.macroEnabled.12"]
    `application_vndmsexceladdinmacroEnabled12
  | [@bs.as "application/vnd.ms-excel.sheet.binary.macroEnabled.12"]
    `application_vndmsexcelsheetbinarymacroEnabled12
  | [@bs.as "application/vnd.ms-excel.sheet.macroEnabled.12"]
    `application_vndmsexcelsheetmacroEnabled12
  | [@bs.as "application/vnd.ms-excel.template.macroEnabled.12"]
    `application_vndmsexceltemplatemacroEnabled12
  | [@bs.as "application/vnd.ms-fontobject"] `application_vndmsfontobject
  | [@bs.as "application/vnd.ms-htmlhelp"] `application_vndmshtmlhelp
  | [@bs.as "application/vnd.ms-ims"] `application_vndmsims
  | [@bs.as "application/vnd.ms-lrm"] `application_vndmslrm
  | [@bs.as "application/vnd.ms-office.activeX+xml"]
    `application_vndmsofficeactiveXxml
  | [@bs.as "application/vnd.ms-officetheme"] `application_vndmsofficetheme
  | [@bs.as "application/vnd.ms-playready.initiator+xml"]
    `application_vndmsplayreadyinitiatorxml
  | [@bs.as "application/vnd.ms-powerpoint"] `application_vndmspowerpoint
  | [@bs.as "application/vnd.ms-powerpoint.addin.macroEnabled.12"]
    `application_vndmspowerpointaddinmacroEnabled12
  | [@bs.as "application/vnd.ms-powerpoint.presentation.macroEnabled.12"]
    `application_vndmspowerpointpresentationmacroEnabled12
  | [@bs.as "application/vnd.ms-powerpoint.slide.macroEnabled.12"]
    `application_vndmspowerpointslidemacroEnabled12
  | [@bs.as "application/vnd.ms-powerpoint.slideshow.macroEnabled.12"]
    `application_vndmspowerpointslideshowmacroEnabled12
  | [@bs.as "application/vnd.ms-powerpoint.template.macroEnabled.12"]
    `application_vndmspowerpointtemplatemacroEnabled12
  | [@bs.as "application/vnd.ms-PrintDeviceCapabilities+xml"]
    `application_vndmsPrintDeviceCapabilitiesxml
  | [@bs.as "application/vnd.ms-PrintSchemaTicket+xml"]
    `application_vndmsPrintSchemaTicketxml
  | [@bs.as "application/vnd.ms-project"] `application_vndmsproject
  | [@bs.as "application/vnd.ms-tnef"] `application_vndmstnef
  | [@bs.as "application/vnd.ms-windows.devicepairing"]
    `application_vndmswindowsdevicepairing
  | [@bs.as "application/vnd.ms-windows.nwprinting.oob"]
    `application_vndmswindowsnwprintingoob
  | [@bs.as "application/vnd.ms-windows.printerpairing"]
    `application_vndmswindowsprinterpairing
  | [@bs.as "application/vnd.ms-windows.wsd.oob"]
    `application_vndmswindowswsdoob
  | [@bs.as "application/vnd.ms-wmdrm.lic-chlg-req"]
    `application_vndmswmdrmlicchlgreq
  | [@bs.as "application/vnd.ms-wmdrm.lic-resp"] `application_vndmswmdrmlicresp
  | [@bs.as "application/vnd.ms-wmdrm.meter-chlg-req"]
    `application_vndmswmdrmmeterchlgreq
  | [@bs.as "application/vnd.ms-wmdrm.meter-resp"]
    `application_vndmswmdrmmeterresp
  | [@bs.as "application/vnd.ms-word.document.macroEnabled.12"]
    `application_vndmsworddocumentmacroEnabled12
  | [@bs.as "application/vnd.ms-word.template.macroEnabled.12"]
    `application_vndmswordtemplatemacroEnabled12
  | [@bs.as "application/vnd.ms-works"] `application_vndmsworks
  | [@bs.as "application/vnd.ms-wpl"] `application_vndmswpl
  | [@bs.as "application/vnd.ms-xpsdocument"] `application_vndmsxpsdocument
  | [@bs.as "application/vnd.msa-disk-image"] `application_vndmsadiskimage
  | [@bs.as "application/vnd.mseq"] `application_vndmseq
  | [@bs.as "application/vnd.msign"] `application_vndmsign
  | [@bs.as "application/vnd.multiad.creator"] `application_vndmultiadcreator
  | [@bs.as "application/vnd.multiad.creator.cif"]
    `application_vndmultiadcreatorcif
  | [@bs.as "application/vnd.musician"] `application_vndmusician
  | [@bs.as "application/vnd.music-niff"] `application_vndmusicniff
  | [@bs.as "application/vnd.muvee.style"] `application_vndmuveestyle
  | [@bs.as "application/vnd.mynfc"] `application_vndmynfc
  | [@bs.as "application/vnd.ncd.control"] `application_vndncdcontrol
  | [@bs.as "application/vnd.ncd.reference"] `application_vndncdreference
  | [@bs.as "application/vnd.nearst.inv+json"] `application_vndnearstinvjson
  | [@bs.as "application/vnd.nervana"] `application_vndnervana
  | [@bs.as "application/vnd.netfpx"] `application_vndnetfpx
  | [@bs.as "application/vnd.neurolanguage.nlu"]
    `application_vndneurolanguagenlu
  | [@bs.as "application/vnd.nintendo.snes.rom"]
    `application_vndnintendosnesrom
  | [@bs.as "application/vnd.nintendo.nitro.rom"]
    `application_vndnintendonitrorom
  | [@bs.as "application/vnd.nitf"] `application_vndnitf
  | [@bs.as "application/vnd.noblenet-directory"]
    `application_vndnoblenetdirectory
  | [@bs.as "application/vnd.noblenet-sealer"] `application_vndnoblenetsealer
  | [@bs.as "application/vnd.noblenet-web"] `application_vndnoblenetweb
  | [@bs.as "application/vnd.nokia.catalogs"] `application_vndnokiacatalogs
  | [@bs.as "application/vnd.nokia.conml+wbxml"]
    `application_vndnokiaconmlwbxml
  | [@bs.as "application/vnd.nokia.conml+xml"] `application_vndnokiaconmlxml
  | [@bs.as "application/vnd.nokia.iptv.config+xml"]
    `application_vndnokiaiptvconfigxml
  | [@bs.as "application/vnd.nokia.iSDS-radio-presets"]
    `application_vndnokiaiSDSradiopresets
  | [@bs.as "application/vnd.nokia.landmark+wbxml"]
    `application_vndnokialandmarkwbxml
  | [@bs.as "application/vnd.nokia.landmark+xml"]
    `application_vndnokialandmarkxml
  | [@bs.as "application/vnd.nokia.landmarkcollection+xml"]
    `application_vndnokialandmarkcollectionxml
  | [@bs.as "application/vnd.nokia.ncd"] `application_vndnokiancd
  | [@bs.as "application/vnd.nokia.n-gage.ac+xml"]
    `application_vndnokiangageacxml
  | [@bs.as "application/vnd.nokia.n-gage.data"] `application_vndnokiangagedata
  | [@bs.as "application/vnd.nokia.pcd+wbxml"] `application_vndnokiapcdwbxml
  | [@bs.as "application/vnd.nokia.pcd+xml"] `application_vndnokiapcdxml
  | [@bs.as "application/vnd.nokia.radio-preset"]
    `application_vndnokiaradiopreset
  | [@bs.as "application/vnd.nokia.radio-presets"]
    `application_vndnokiaradiopresets
  | [@bs.as "application/vnd.novadigm.EDM"] `application_vndnovadigmEDM
  | [@bs.as "application/vnd.novadigm.EDX"] `application_vndnovadigmEDX
  | [@bs.as "application/vnd.novadigm.EXT"] `application_vndnovadigmEXT
  | [@bs.as "application/vnd.ntt-local.content-share"]
    `application_vndnttlocalcontentshare
  | [@bs.as "application/vnd.ntt-local.file-transfer"]
    `application_vndnttlocalfiletransfer
  | [@bs.as "application/vnd.ntt-local.ogw_remote-access"]
    `application_vndnttlocalogw_remoteaccess
  | [@bs.as "application/vnd.ntt-local.sip-ta_remote"]
    `application_vndnttlocalsipta_remote
  | [@bs.as "application/vnd.ntt-local.sip-ta_tcp_stream"]
    `application_vndnttlocalsipta_tcp_stream
  | [@bs.as "application/vnd.oasis.opendocument.chart"]
    `application_vndoasisopendocumentchart
  | [@bs.as "application/vnd.oasis.opendocument.chart-template"]
    `application_vndoasisopendocumentcharttemplate
  | [@bs.as "application/vnd.oasis.opendocument.database"]
    `application_vndoasisopendocumentdatabase
  | [@bs.as "application/vnd.oasis.opendocument.formula"]
    `application_vndoasisopendocumentformula
  | [@bs.as "application/vnd.oasis.opendocument.formula-template"]
    `application_vndoasisopendocumentformulatemplate
  | [@bs.as "application/vnd.oasis.opendocument.graphics"]
    `application_vndoasisopendocumentgraphics
  | [@bs.as "application/vnd.oasis.opendocument.graphics-template"]
    `application_vndoasisopendocumentgraphicstemplate
  | [@bs.as "application/vnd.oasis.opendocument.image"]
    `application_vndoasisopendocumentimage
  | [@bs.as "application/vnd.oasis.opendocument.image-template"]
    `application_vndoasisopendocumentimagetemplate
  | [@bs.as "application/vnd.oasis.opendocument.presentation"]
    `application_vndoasisopendocumentpresentation
  | [@bs.as "application/vnd.oasis.opendocument.presentation-template"]
    `application_vndoasisopendocumentpresentationtemplate
  | [@bs.as "application/vnd.oasis.opendocument.spreadsheet"]
    `application_vndoasisopendocumentspreadsheet
  | [@bs.as "application/vnd.oasis.opendocument.spreadsheet-template"]
    `application_vndoasisopendocumentspreadsheettemplate
  | [@bs.as "application/vnd.oasis.opendocument.text"]
    `application_vndoasisopendocumenttext
  | [@bs.as "application/vnd.oasis.opendocument.text-master"]
    `application_vndoasisopendocumenttextmaster
  | [@bs.as "application/vnd.oasis.opendocument.text-template"]
    `application_vndoasisopendocumenttexttemplate
  | [@bs.as "application/vnd.oasis.opendocument.text-web"]
    `application_vndoasisopendocumenttextweb
  | [@bs.as "application/vnd.obn"] `application_vndobn
  | [@bs.as "application/vnd.ocf+cbor"] `application_vndocfcbor
  | [@bs.as "application/vnd.oftn.l10n+json"] `application_vndoftnl10njson
  | [@bs.as "application/vnd.oipf.contentaccessdownload+xml"]
    `application_vndoipfcontentaccessdownloadxml
  | [@bs.as "application/vnd.oipf.contentaccessstreaming+xml"]
    `application_vndoipfcontentaccessstreamingxml
  | [@bs.as "application/vnd.oipf.cspg-hexbinary"]
    `application_vndoipfcspghexbinary
  | [@bs.as "application/vnd.oipf.dae.svg+xml"] `application_vndoipfdaesvgxml
  | [@bs.as "application/vnd.oipf.dae.xhtml+xml"]
    `application_vndoipfdaexhtmlxml
  | [@bs.as "application/vnd.oipf.mippvcontrolmessage+xml"]
    `application_vndoipfmippvcontrolmessagexml
  | [@bs.as "application/vnd.oipf.pae.gem"] `application_vndoipfpaegem
  | [@bs.as "application/vnd.oipf.spdiscovery+xml"]
    `application_vndoipfspdiscoveryxml
  | [@bs.as "application/vnd.oipf.spdlist+xml"] `application_vndoipfspdlistxml
  | [@bs.as "application/vnd.oipf.ueprofile+xml"]
    `application_vndoipfueprofilexml
  | [@bs.as "application/vnd.oipf.userprofile+xml"]
    `application_vndoipfuserprofilexml
  | [@bs.as "application/vnd.olpc-sugar"] `application_vndolpcsugar
  | [@bs.as "application/vnd.oma.bcast.associated-procedure-parameter+xml"]
    `application_vndomabcastassociatedprocedureparameterxml
  | [@bs.as "application/vnd.oma.bcast.drm-trigger+xml"]
    `application_vndomabcastdrmtriggerxml
  | [@bs.as "application/vnd.oma.bcast.imd+xml"] `application_vndomabcastimdxml
  | [@bs.as "application/vnd.oma.bcast.ltkm"] `application_vndomabcastltkm
  | [@bs.as "application/vnd.oma.bcast.notification+xml"]
    `application_vndomabcastnotificationxml
  | [@bs.as "application/vnd.oma.bcast.provisioningtrigger"]
    `application_vndomabcastprovisioningtrigger
  | [@bs.as "application/vnd.oma.bcast.sgboot"] `application_vndomabcastsgboot
  | [@bs.as "application/vnd.oma.bcast.sgdd+xml"]
    `application_vndomabcastsgddxml
  | [@bs.as "application/vnd.oma.bcast.sgdu"] `application_vndomabcastsgdu
  | [@bs.as "application/vnd.oma.bcast.simple-symbol-container"]
    `application_vndomabcastsimplesymbolcontainer
  | [@bs.as "application/vnd.oma.bcast.smartcard-trigger+xml"]
    `application_vndomabcastsmartcardtriggerxml
  | [@bs.as "application/vnd.oma.bcast.sprov+xml"]
    `application_vndomabcastsprovxml
  | [@bs.as "application/vnd.oma.bcast.stkm"] `application_vndomabcaststkm
  | [@bs.as "application/vnd.oma.cab-address-book+xml"]
    `application_vndomacabaddressbookxml
  | [@bs.as "application/vnd.oma.cab-feature-handler+xml"]
    `application_vndomacabfeaturehandlerxml
  | [@bs.as "application/vnd.oma.cab-pcc+xml"] `application_vndomacabpccxml
  | [@bs.as "application/vnd.oma.cab-subs-invite+xml"]
    `application_vndomacabsubsinvitexml
  | [@bs.as "application/vnd.oma.cab-user-prefs+xml"]
    `application_vndomacabuserprefsxml
  | [@bs.as "application/vnd.oma.dcd"] `application_vndomadcd
  | [@bs.as "application/vnd.oma.dcdc"] `application_vndomadcdc
  | [@bs.as "application/vnd.oma.dd2+xml"] `application_vndomadd2xml
  | [@bs.as "application/vnd.oma.drm.risd+xml"] `application_vndomadrmrisdxml
  | [@bs.as "application/vnd.oma.group-usage-list+xml"]
    `application_vndomagroupusagelistxml
  | [@bs.as "application/vnd.oma.lwm2m+json"] `application_vndomalwm2mjson
  | [@bs.as "application/vnd.oma.lwm2m+tlv"] `application_vndomalwm2mtlv
  | [@bs.as "application/vnd.oma.pal+xml"] `application_vndomapalxml
  | [@bs.as "application/vnd.oma.poc.detailed-progress-report+xml"]
    `application_vndomapocdetailedprogressreportxml
  | [@bs.as "application/vnd.oma.poc.final-report+xml"]
    `application_vndomapocfinalreportxml
  | [@bs.as "application/vnd.oma.poc.groups+xml"]
    `application_vndomapocgroupsxml
  | [@bs.as "application/vnd.oma.poc.invocation-descriptor+xml"]
    `application_vndomapocinvocationdescriptorxml
  | [@bs.as "application/vnd.oma.poc.optimized-progress-report+xml"]
    `application_vndomapocoptimizedprogressreportxml
  | [@bs.as "application/vnd.oma.push"] `application_vndomapush
  | [@bs.as "application/vnd.oma.scidm.messages+xml"]
    `application_vndomascidmmessagesxml
  | [@bs.as "application/vnd.oma.xcap-directory+xml"]
    `application_vndomaxcapdirectoryxml
  | [@bs.as "application/vnd.omads-email+xml"] `application_vndomadsemailxml
  | [@bs.as "application/vnd.omads-file+xml"] `application_vndomadsfilexml
  | [@bs.as "application/vnd.omads-folder+xml"] `application_vndomadsfolderxml
  | [@bs.as "application/vnd.omaloc-supl-init"] `application_vndomalocsuplinit
  | [@bs.as "application/vnd.oma-scws-config"] `application_vndomascwsconfig
  | [@bs.as "application/vnd.oma-scws-http-request"]
    `application_vndomascwshttprequest
  | [@bs.as "application/vnd.oma-scws-http-response"]
    `application_vndomascwshttpresponse
  | [@bs.as "application/vnd.onepager"] `application_vndonepager
  | [@bs.as "application/vnd.onepagertamp"] `application_vndonepagertamp
  | [@bs.as "application/vnd.onepagertamx"] `application_vndonepagertamx
  | [@bs.as "application/vnd.onepagertat"] `application_vndonepagertat
  | [@bs.as "application/vnd.onepagertatp"] `application_vndonepagertatp
  | [@bs.as "application/vnd.onepagertatx"] `application_vndonepagertatx
  | [@bs.as "application/vnd.openblox.game-binary"]
    `application_vndopenbloxgamebinary
  | [@bs.as "application/vnd.openblox.game+xml"]
    `application_vndopenbloxgamexml
  | [@bs.as "application/vnd.openeye.oeb"] `application_vndopeneyeoeb
  | [@bs.as "application/vnd.openstreetmap.data+xml"]
    `application_vndopenstreetmapdataxml
  | [@bs.as
      "application/vnd.openxmlformats-officedocument.custom-properties+xml"
    ]
    `application_vndopenxmlformatsofficedocumentcustompropertiesxml
  | [@bs.as
      "application/vnd.openxmlformats-officedocument.customXmlProperties+xml"
    ]
    `application_vndopenxmlformatsofficedocumentcustomXmlPropertiesxml
  | [@bs.as "application/vnd.openxmlformats-officedocument.drawing+xml"]
    `application_vndopenxmlformatsofficedocumentdrawingxml
  | [@bs.as
      "application/vnd.openxmlformats-officedocument.drawingml.chart+xml"
    ]
    `application_vndopenxmlformatsofficedocumentdrawingmlchartxml
  | [@bs.as
      "application/vnd.openxmlformats-officedocument.drawingml.chartshapes+xml"
    ]
    `application_vndopenxmlformatsofficedocumentdrawingmlchartshapesxml
  | [@bs.as
      "application/vnd.openxmlformats-officedocument.drawingml.diagramColors+xml"
    ]
    `application_vndopenxmlformatsofficedocumentdrawingmldiagramColorsxml
  | [@bs.as
      "application/vnd.openxmlformats-officedocument.drawingml.diagramData+xml"
    ]
    `application_vndopenxmlformatsofficedocumentdrawingmldiagramDataxml
  | [@bs.as
      "application/vnd.openxmlformats-officedocument.drawingml.diagramLayout+xml"
    ]
    `application_vndopenxmlformatsofficedocumentdrawingmldiagramLayoutxml
  | [@bs.as
      "application/vnd.openxmlformats-officedocument.drawingml.diagramStyle+xml"
    ]
    `application_vndopenxmlformatsofficedocumentdrawingmldiagramStylexml
  | [@bs.as
      "application/vnd.openxmlformats-officedocument.extended-properties+xml"
    ]
    `application_vndopenxmlformatsofficedocumentextendedpropertiesxml
  | [@bs.as
      "application/vnd.openxmlformats-officedocument.presentationml.commentAuthors+xml"
    ]
    `application_vndopenxmlformatsofficedocumentpresentationmlcommentAuthorsxml
  | [@bs.as
      "application/vnd.openxmlformats-officedocument.presentationml.comments+xml"
    ]
    `application_vndopenxmlformatsofficedocumentpresentationmlcommentsxml
  | [@bs.as
      "application/vnd.openxmlformats-officedocument.presentationml.handoutMaster+xml"
    ]
    `application_vndopenxmlformatsofficedocumentpresentationmlhandoutMasterxml
  | [@bs.as
      "application/vnd.openxmlformats-officedocument.presentationml.notesMaster+xml"
    ]
    `application_vndopenxmlformatsofficedocumentpresentationmlnotesMasterxml
  | [@bs.as
      "application/vnd.openxmlformats-officedocument.presentationml.notesSlide+xml"
    ]
    `application_vndopenxmlformatsofficedocumentpresentationmlnotesSlidexml
  | [@bs.as
      "application/vnd.openxmlformats-officedocument.presentationml.presentation"
    ]
    `application_vndopenxmlformatsofficedocumentpresentationmlpresentation
  | [@bs.as
      "application/vnd.openxmlformats-officedocument.presentationml.presentation.main+xml"
    ]
    `application_vndopenxmlformatsofficedocumentpresentationmlpresentationmainxml
  | [@bs.as
      "application/vnd.openxmlformats-officedocument.presentationml.presProps+xml"
    ]
    `application_vndopenxmlformatsofficedocumentpresentationmlpresPropsxml
  | [@bs.as
      "application/vnd.openxmlformats-officedocument.presentationml.slide"
    ]
    `application_vndopenxmlformatsofficedocumentpresentationmlslide
  | [@bs.as
      "application/vnd.openxmlformats-officedocument.presentationml.slide+xml"
    ]
    `application_vndopenxmlformatsofficedocumentpresentationmlslidexml
  | [@bs.as
      "application/vnd.openxmlformats-officedocument.presentationml.slideLayout+xml"
    ]
    `application_vndopenxmlformatsofficedocumentpresentationmlslideLayoutxml
  | [@bs.as
      "application/vnd.openxmlformats-officedocument.presentationml.slideMaster+xml"
    ]
    `application_vndopenxmlformatsofficedocumentpresentationmlslideMasterxml
  | [@bs.as
      "application/vnd.openxmlformats-officedocument.presentationml.slideshow"
    ]
    `application_vndopenxmlformatsofficedocumentpresentationmlslideshow
  | [@bs.as
      "application/vnd.openxmlformats-officedocument.presentationml.slideshow.main+xml"
    ]
    `application_vndopenxmlformatsofficedocumentpresentationmlslideshowmainxml
  | [@bs.as
      "application/vnd.openxmlformats-officedocument.presentationml.slideUpdateInfo+xml"
    ]
    `application_vndopenxmlformatsofficedocumentpresentationmlslideUpdateInfoxml
  | [@bs.as
      "application/vnd.openxmlformats-officedocument.presentationml.tableStyles+xml"
    ]
    `application_vndopenxmlformatsofficedocumentpresentationmltableStylesxml
  | [@bs.as
      "application/vnd.openxmlformats-officedocument.presentationml.tags+xml"
    ]
    `application_vndopenxmlformatsofficedocumentpresentationmltagsxml
  | [@bs.as
      "application/vnd.openxmlformats-officedocument.presentationml-template"
    ]
    `application_vndopenxmlformatsofficedocumentpresentationmltemplate
  | [@bs.as
      "application/vnd.openxmlformats-officedocument.presentationml.template.main+xml"
    ]
    `application_vndopenxmlformatsofficedocumentpresentationmltemplatemainxml
  | [@bs.as
      "application/vnd.openxmlformats-officedocument.presentationml.viewProps+xml"
    ]
    `application_vndopenxmlformatsofficedocumentpresentationmlviewPropsxml
  | [@bs.as
      "application/vnd.openxmlformats-officedocument.spreadsheetml.calcChain+xml"
    ]
    `application_vndopenxmlformatsofficedocumentspreadsheetmlcalcChainxml
  | [@bs.as
      "application/vnd.openxmlformats-officedocument.spreadsheetml.chartsheet+xml"
    ]
    `application_vndopenxmlformatsofficedocumentspreadsheetmlchartsheetxml
  | [@bs.as
      "application/vnd.openxmlformats-officedocument.spreadsheetml.comments+xml"
    ]
    `application_vndopenxmlformatsofficedocumentspreadsheetmlcommentsxml
  | [@bs.as
      "application/vnd.openxmlformats-officedocument.spreadsheetml.connections+xml"
    ]
    `application_vndopenxmlformatsofficedocumentspreadsheetmlconnectionsxml
  | [@bs.as
      "application/vnd.openxmlformats-officedocument.spreadsheetml.dialogsheet+xml"
    ]
    `application_vndopenxmlformatsofficedocumentspreadsheetmldialogsheetxml
  | [@bs.as
      "application/vnd.openxmlformats-officedocument.spreadsheetml.externalLink+xml"
    ]
    `application_vndopenxmlformatsofficedocumentspreadsheetmlexternalLinkxml
  | [@bs.as
      "application/vnd.openxmlformats-officedocument.spreadsheetml.pivotCacheDefinition+xml"
    ]
    `application_vndopenxmlformatsofficedocumentspreadsheetmlpivotCacheDefinitionxml
  | [@bs.as
      "application/vnd.openxmlformats-officedocument.spreadsheetml.pivotCacheRecords+xml"
    ]
    `application_vndopenxmlformatsofficedocumentspreadsheetmlpivotCacheRecordsxml
  | [@bs.as
      "application/vnd.openxmlformats-officedocument.spreadsheetml.pivotTable+xml"
    ]
    `application_vndopenxmlformatsofficedocumentspreadsheetmlpivotTablexml
  | [@bs.as
      "application/vnd.openxmlformats-officedocument.spreadsheetml.queryTable+xml"
    ]
    `application_vndopenxmlformatsofficedocumentspreadsheetmlqueryTablexml
  | [@bs.as
      "application/vnd.openxmlformats-officedocument.spreadsheetml.revisionHeaders+xml"
    ]
    `application_vndopenxmlformatsofficedocumentspreadsheetmlrevisionHeadersxml
  | [@bs.as
      "application/vnd.openxmlformats-officedocument.spreadsheetml.revisionLog+xml"
    ]
    `application_vndopenxmlformatsofficedocumentspreadsheetmlrevisionLogxml
  | [@bs.as
      "application/vnd.openxmlformats-officedocument.spreadsheetml.sharedStrings+xml"
    ]
    `application_vndopenxmlformatsofficedocumentspreadsheetmlsharedStringsxml
  | [@bs.as
      "application/vnd.openxmlformats-officedocument.spreadsheetml.sheet"
    ]
    `application_vndopenxmlformatsofficedocumentspreadsheetmlsheet
  | [@bs.as
      "application/vnd.openxmlformats-officedocument.spreadsheetml.sheet.main+xml"
    ]
    `application_vndopenxmlformatsofficedocumentspreadsheetmlsheetmainxml
  | [@bs.as
      "application/vnd.openxmlformats-officedocument.spreadsheetml.sheetMetadata+xml"
    ]
    `application_vndopenxmlformatsofficedocumentspreadsheetmlsheetMetadataxml
  | [@bs.as
      "application/vnd.openxmlformats-officedocument.spreadsheetml.styles+xml"
    ]
    `application_vndopenxmlformatsofficedocumentspreadsheetmlstylesxml
  | [@bs.as
      "application/vnd.openxmlformats-officedocument.spreadsheetml.table+xml"
    ]
    `application_vndopenxmlformatsofficedocumentspreadsheetmltablexml
  | [@bs.as
      "application/vnd.openxmlformats-officedocument.spreadsheetml.tableSingleCells+xml"
    ]
    `application_vndopenxmlformatsofficedocumentspreadsheetmltableSingleCellsxml
  | [@bs.as
      "application/vnd.openxmlformats-officedocument.spreadsheetml-template"
    ]
    `application_vndopenxmlformatsofficedocumentspreadsheetmltemplate
  | [@bs.as
      "application/vnd.openxmlformats-officedocument.spreadsheetml.template.main+xml"
    ]
    `application_vndopenxmlformatsofficedocumentspreadsheetmltemplatemainxml
  | [@bs.as
      "application/vnd.openxmlformats-officedocument.spreadsheetml.userNames+xml"
    ]
    `application_vndopenxmlformatsofficedocumentspreadsheetmluserNamesxml
  | [@bs.as
      "application/vnd.openxmlformats-officedocument.spreadsheetml.volatileDependencies+xml"
    ]
    `application_vndopenxmlformatsofficedocumentspreadsheetmlvolatileDependenciesxml
  | [@bs.as
      "application/vnd.openxmlformats-officedocument.spreadsheetml.worksheet+xml"
    ]
    `application_vndopenxmlformatsofficedocumentspreadsheetmlworksheetxml
  | [@bs.as "application/vnd.openxmlformats-officedocument.theme+xml"]
    `application_vndopenxmlformatsofficedocumentthemexml
  | [@bs.as "application/vnd.openxmlformats-officedocument.themeOverride+xml"]
    `application_vndopenxmlformatsofficedocumentthemeOverridexml
  | [@bs.as "application/vnd.openxmlformats-officedocument.vmlDrawing"]
    `application_vndopenxmlformatsofficedocumentvmlDrawing
  | [@bs.as
      "application/vnd.openxmlformats-officedocument.wordprocessingml.comments+xml"
    ]
    `application_vndopenxmlformatsofficedocumentwordprocessingmlcommentsxml
  | [@bs.as
      "application/vnd.openxmlformats-officedocument.wordprocessingml.document"
    ]
    `application_vndopenxmlformatsofficedocumentwordprocessingmldocument
  | [@bs.as
      "application/vnd.openxmlformats-officedocument.wordprocessingml.document.glossary+xml"
    ]
    `application_vndopenxmlformatsofficedocumentwordprocessingmldocumentglossaryxml
  | [@bs.as
      "application/vnd.openxmlformats-officedocument.wordprocessingml.document.main+xml"
    ]
    `application_vndopenxmlformatsofficedocumentwordprocessingmldocumentmainxml
  | [@bs.as
      "application/vnd.openxmlformats-officedocument.wordprocessingml.endnotes+xml"
    ]
    `application_vndopenxmlformatsofficedocumentwordprocessingmlendnotesxml
  | [@bs.as
      "application/vnd.openxmlformats-officedocument.wordprocessingml.fontTable+xml"
    ]
    `application_vndopenxmlformatsofficedocumentwordprocessingmlfontTablexml
  | [@bs.as
      "application/vnd.openxmlformats-officedocument.wordprocessingml.footer+xml"
    ]
    `application_vndopenxmlformatsofficedocumentwordprocessingmlfooterxml
  | [@bs.as
      "application/vnd.openxmlformats-officedocument.wordprocessingml.footnotes+xml"
    ]
    `application_vndopenxmlformatsofficedocumentwordprocessingmlfootnotesxml
  | [@bs.as
      "application/vnd.openxmlformats-officedocument.wordprocessingml.numbering+xml"
    ]
    `application_vndopenxmlformatsofficedocumentwordprocessingmlnumberingxml
  | [@bs.as
      "application/vnd.openxmlformats-officedocument.wordprocessingml.settings+xml"
    ]
    `application_vndopenxmlformatsofficedocumentwordprocessingmlsettingsxml
  | [@bs.as
      "application/vnd.openxmlformats-officedocument.wordprocessingml.styles+xml"
    ]
    `application_vndopenxmlformatsofficedocumentwordprocessingmlstylesxml
  | [@bs.as
      "application/vnd.openxmlformats-officedocument.wordprocessingml-template"
    ]
    `application_vndopenxmlformatsofficedocumentwordprocessingmltemplate
  | [@bs.as
      "application/vnd.openxmlformats-officedocument.wordprocessingml.template.main+xml"
    ]
    `application_vndopenxmlformatsofficedocumentwordprocessingmltemplatemainxml
  | [@bs.as
      "application/vnd.openxmlformats-officedocument.wordprocessingml.webSettings+xml"
    ]
    `application_vndopenxmlformatsofficedocumentwordprocessingmlwebSettingsxml
  | [@bs.as "application/vnd.openxmlformats-package.core-properties+xml"]
    `application_vndopenxmlformatspackagecorepropertiesxml
  | [@bs.as
      "application/vnd.openxmlformats-package.digital-signature-xmlsignature+xml"
    ]
    `application_vndopenxmlformatspackagedigitalsignaturexmlsignaturexml
  | [@bs.as "application/vnd.openxmlformats-package.relationships+xml"]
    `application_vndopenxmlformatspackagerelationshipsxml
  | [@bs.as "application/vnd.oracle.resource+json"]
    `application_vndoracleresourcejson
  | [@bs.as "application/vnd.orange.indata"] `application_vndorangeindata
  | [@bs.as "application/vnd.osa.netdeploy"] `application_vndosanetdeploy
  | [@bs.as "application/vnd.osgeo.mapguide.package"]
    `application_vndosgeomapguidepackage
  | [@bs.as "application/vnd.osgi.bundle"] `application_vndosgibundle
  | [@bs.as "application/vnd.osgi.dp"] `application_vndosgidp
  | [@bs.as "application/vnd.osgi.subsystem"] `application_vndosgisubsystem
  | [@bs.as "application/vnd.otps.ct-kip+xml"] `application_vndotpsctkipxml
  | [@bs.as "application/vnd.oxli.countgraph"] `application_vndoxlicountgraph
  | [@bs.as "application/vnd.pagerduty+json"] `application_vndpagerdutyjson
  | [@bs.as "application/vnd.palm"] `application_vndpalm
  | [@bs.as "application/vnd.panoply"] `application_vndpanoply
  | [@bs.as "application/vnd.paos+xml"] `application_vndpaosxml
  | [@bs.as "application/vnd.patentdive"] `application_vndpatentdive
  | [@bs.as "application/vnd.pawaafile"] `application_vndpawaafile
  | [@bs.as "application/vnd.pcos"] `application_vndpcos
  | [@bs.as "application/vnd.pg.format"] `application_vndpgformat
  | [@bs.as "application/vnd.pg.osasli"] `application_vndpgosasli
  | [@bs.as "application/vnd.piaccess.application-licence"]
    `application_vndpiaccessapplicationlicence
  | [@bs.as "application/vnd.picsel"] `application_vndpicsel
  | [@bs.as "application/vnd.pmi.widget"] `application_vndpmiwidget
  | [@bs.as "application/vnd.poc.group-advertisement+xml"]
    `application_vndpocgroupadvertisementxml
  | [@bs.as "application/vnd.pocketlearn"] `application_vndpocketlearn
  | [@bs.as "application/vnd.powerbuilder6"] `application_vndpowerbuilder6
  | [@bs.as "application/vnd.powerbuilder6-s"] `application_vndpowerbuilder6s
  | [@bs.as "application/vnd.powerbuilder7"] `application_vndpowerbuilder7
  | [@bs.as "application/vnd.powerbuilder75"] `application_vndpowerbuilder75
  | [@bs.as "application/vnd.powerbuilder75-s"] `application_vndpowerbuilder75s
  | [@bs.as "application/vnd.powerbuilder7-s"] `application_vndpowerbuilder7s
  | [@bs.as "application/vnd.preminet"] `application_vndpreminet
  | [@bs.as "application/vnd.previewsystems.box"]
    `application_vndpreviewsystemsbox
  | [@bs.as "application/vnd.proteus.magazine"] `application_vndproteusmagazine
  | [@bs.as "application/vnd.psfs"] `application_vndpsfs
  | [@bs.as "application/vnd.publishare-delta-tree"]
    `application_vndpublisharedeltatree
  | [@bs.as "application/vnd.pvi.ptid1"] `application_vndpviptid1
  | [@bs.as "application/vnd.pwg-multiplexed"] `application_vndpwgmultiplexed
  | [@bs.as "application/vnd.pwg-xhtml-print+xml"]
    `application_vndpwgxhtmlprintxml
  | [@bs.as "application/vnd.qualcomm.brew-app-res"]
    `application_vndqualcommbrewappres
  | [@bs.as "application/vnd.quarantainenet"] `application_vndquarantainenet
  | [@bs.as "application/vnd.Quark.QuarkXPress"]
    `application_vndQuarkQuarkXPress
  | [@bs.as "application/vnd.quobject-quoxdocument"]
    `application_vndquobjectquoxdocument
  | [@bs.as "application/vnd.radisys.moml+xml"] `application_vndradisysmomlxml
  | [@bs.as "application/vnd.radisys.msml-audit-conf+xml"]
    `application_vndradisysmsmlauditconfxml
  | [@bs.as "application/vnd.radisys.msml-audit-conn+xml"]
    `application_vndradisysmsmlauditconnxml
  | [@bs.as "application/vnd.radisys.msml-audit-dialog+xml"]
    `application_vndradisysmsmlauditdialogxml
  | [@bs.as "application/vnd.radisys.msml-audit-stream+xml"]
    `application_vndradisysmsmlauditstreamxml
  | [@bs.as "application/vnd.radisys.msml-audit+xml"]
    `application_vndradisysmsmlauditxml
  | [@bs.as "application/vnd.radisys.msml-conf+xml"]
    `application_vndradisysmsmlconfxml
  | [@bs.as "application/vnd.radisys.msml-dialog-base+xml"]
    `application_vndradisysmsmldialogbasexml
  | [@bs.as "application/vnd.radisys.msml-dialog-fax-detect+xml"]
    `application_vndradisysmsmldialogfaxdetectxml
  | [@bs.as "application/vnd.radisys.msml-dialog-fax-sendrecv+xml"]
    `application_vndradisysmsmldialogfaxsendrecvxml
  | [@bs.as "application/vnd.radisys.msml-dialog-group+xml"]
    `application_vndradisysmsmldialoggroupxml
  | [@bs.as "application/vnd.radisys.msml-dialog-speech+xml"]
    `application_vndradisysmsmldialogspeechxml
  | [@bs.as "application/vnd.radisys.msml-dialog-transform+xml"]
    `application_vndradisysmsmldialogtransformxml
  | [@bs.as "application/vnd.radisys.msml-dialog+xml"]
    `application_vndradisysmsmldialogxml
  | [@bs.as "application/vnd.radisys.msml+xml"] `application_vndradisysmsmlxml
  | [@bs.as "application/vnd.rainstor.data"] `application_vndrainstordata
  | [@bs.as "application/vnd.rapid"] `application_vndrapid
  | [@bs.as "application/vnd.rar"] `application_vndrar
  | [@bs.as "application/vnd.realvnc.bed"] `application_vndrealvncbed
  | [@bs.as "application/vnd.recordare.musicxml"]
    `application_vndrecordaremusicxml
  | [@bs.as "application/vnd.recordare.musicxml+xml"]
    `application_vndrecordaremusicxmlxml
  | [@bs.as "application/vnd.renlearn.rlprint"] `application_vndrenlearnrlprint
  | [@bs.as "application/vnd.restful+json"] `application_vndrestfuljson
  | [@bs.as "application/vnd.rig.cryptonote"] `application_vndrigcryptonote
  | [@bs.as "application/vnd.route66.link66+xml"]
    `application_vndroute66link66xml
  | [@bs.as "application/vnd.rs-274x"] `application_vndrs274x
  | [@bs.as "application/vnd.ruckus.download"] `application_vndruckusdownload
  | [@bs.as "application/vnd.s3sms"] `application_vnds3sms
  | [@bs.as "application/vnd.sailingtracker.track"]
    `application_vndsailingtrackertrack
  | [@bs.as "application/vnd.sbm.cid"] `application_vndsbmcid
  | [@bs.as "application/vnd.sbm.mid2"] `application_vndsbmmid2
  | [@bs.as "application/vnd.scribus"] `application_vndscribus
  | [@bs.as "application/vnd.sealed.3df"] `application_vndsealed3df
  | [@bs.as "application/vnd.sealed.csf"] `application_vndsealedcsf
  | [@bs.as "application/vnd.sealed-doc"] `application_vndsealeddoc
  | [@bs.as "application/vnd.sealed-eml"] `application_vndsealedeml
  | [@bs.as "application/vnd.sealed-mht"] `application_vndsealedmht
  | [@bs.as "application/vnd.sealed.net"] `application_vndsealednet
  | [@bs.as "application/vnd.sealed-ppt"] `application_vndsealedppt
  | [@bs.as "application/vnd.sealed-tiff"] `application_vndsealedtiff
  | [@bs.as "application/vnd.sealed-xls"] `application_vndsealedxls
  | [@bs.as "application/vnd.sealedmedia.softseal-html"]
    `application_vndsealedmediasoftsealhtml
  | [@bs.as "application/vnd.sealedmedia.softseal-pdf"]
    `application_vndsealedmediasoftsealpdf
  | [@bs.as "application/vnd.seemail"] `application_vndseemail
  | [@bs.as "application/vnd-sema"] `application_vndsema
  | [@bs.as "application/vnd.semd"] `application_vndsemd
  | [@bs.as "application/vnd.semf"] `application_vndsemf
  | [@bs.as "application/vnd.shana.informed.formdata"]
    `application_vndshanainformedformdata
  | [@bs.as "application/vnd.shana.informed.formtemplate"]
    `application_vndshanainformedformtemplate
  | [@bs.as "application/vnd.shana.informed.interchange"]
    `application_vndshanainformedinterchange
  | [@bs.as "application/vnd.shana.informed.package"]
    `application_vndshanainformedpackage
  | [@bs.as "application/vnd.shootproof+json"] `application_vndshootproofjson
  | [@bs.as "application/vnd.sigrok.session"] `application_vndsigroksession
  | [@bs.as "application/vnd.SimTech-MindMapper"]
    `application_vndSimTechMindMapper
  | [@bs.as "application/vnd.siren+json"] `application_vndsirenjson
  | [@bs.as "application/vnd.smaf"] `application_vndsmaf
  | [@bs.as "application/vnd.smart.notebook"] `application_vndsmartnotebook
  | [@bs.as "application/vnd.smart.teacher"] `application_vndsmartteacher
  | [@bs.as "application/vnd.software602.filler.form+xml"]
    `application_vndsoftware602fillerformxml
  | [@bs.as "application/vnd.software602.filler.form-xml-zip"]
    `application_vndsoftware602fillerformxmlzip
  | [@bs.as "application/vnd.solent.sdkm+xml"] `application_vndsolentsdkmxml
  | [@bs.as "application/vnd.spotfire.dxp"] `application_vndspotfiredxp
  | [@bs.as "application/vnd.spotfire.sfs"] `application_vndspotfiresfs
  | [@bs.as "application/vnd.sqlite3"] `application_vndsqlite3
  | [@bs.as "application/vnd.sss-cod"] `application_vndssscod
  | [@bs.as "application/vnd.sss-dtf"] `application_vndsssdtf
  | [@bs.as "application/vnd.sss-ntf"] `application_vndsssntf
  | [@bs.as "application/vnd.stepmania.package"]
    `application_vndstepmaniapackage
  | [@bs.as "application/vnd.stepmania.stepchart"]
    `application_vndstepmaniastepchart
  | [@bs.as "application/vnd.street-stream"] `application_vndstreetstream
  | [@bs.as "application/vnd.sun.wadl+xml"] `application_vndsunwadlxml
  | [@bs.as "application/vnd.sus-calendar"] `application_vndsuscalendar
  | [@bs.as "application/vnd.svd"] `application_vndsvd
  | [@bs.as "application/vnd.swiftview-ics"] `application_vndswiftviewics
  | [@bs.as "application/vnd.syncml.dm.notification"]
    `application_vndsyncmldmnotification
  | [@bs.as "application/vnd.syncml.dmddf+xml"] `application_vndsyncmldmddfxml
  | [@bs.as "application/vnd.syncml.dmtnds+wbxml"]
    `application_vndsyncmldmtndswbxml
  | [@bs.as "application/vnd.syncml.dmtnds+xml"]
    `application_vndsyncmldmtndsxml
  | [@bs.as "application/vnd.syncml.dmddf+wbxml"]
    `application_vndsyncmldmddfwbxml
  | [@bs.as "application/vnd.syncml.dm+wbxml"] `application_vndsyncmldmwbxml
  | [@bs.as "application/vnd.syncml.dm+xml"] `application_vndsyncmldmxml
  | [@bs.as "application/vnd.syncml.ds.notification"]
    `application_vndsyncmldsnotification
  | [@bs.as "application/vnd.syncml+xml"] `application_vndsyncmlxml
  | [@bs.as "application/vnd.tableschema+json"] `application_vndtableschemajson
  | [@bs.as "application/vnd.tao.intent-module-archive"]
    `application_vndtaointentmodulearchive
  | [@bs.as "application/vnd.tcpdump.pcap"] `application_vndtcpdumppcap
  | [@bs.as "application/vnd.think-cell.ppttc+json"]
    `application_vndthinkcellppttcjson
  | [@bs.as "application/vnd.tml"] `application_vndtml
  | [@bs.as "application/vnd.tmd.mediaflex.api+xml"]
    `application_vndtmdmediaflexapixml
  | [@bs.as "application/vnd.tmobile-livetv"] `application_vndtmobilelivetv
  | [@bs.as "application/vnd.tri.onesource"] `application_vndtrionesource
  | [@bs.as "application/vnd.trid.tpt"] `application_vndtridtpt
  | [@bs.as "application/vnd.triscape.mxs"] `application_vndtriscapemxs
  | [@bs.as "application/vnd.trueapp"] `application_vndtrueapp
  | [@bs.as "application/vnd.truedoc"] `application_vndtruedoc
  | [@bs.as "application/vnd.ubisoft.webplayer"]
    `application_vndubisoftwebplayer
  | [@bs.as "application/vnd.ufdl"] `application_vndufdl
  | [@bs.as "application/vnd.uiq.theme"] `application_vnduiqtheme
  | [@bs.as "application/vnd.umajin"] `application_vndumajin
  | [@bs.as "application/vnd.unity"] `application_vndunity
  | [@bs.as "application/vnd.uoml+xml"] `application_vnduomlxml
  | [@bs.as "application/vnd.uplanet.alert"] `application_vnduplanetalert
  | [@bs.as "application/vnd.uplanet.alert-wbxml"]
    `application_vnduplanetalertwbxml
  | [@bs.as "application/vnd.uplanet.bearer-choice"]
    `application_vnduplanetbearerchoice
  | [@bs.as "application/vnd.uplanet.bearer-choice-wbxml"]
    `application_vnduplanetbearerchoicewbxml
  | [@bs.as "application/vnd.uplanet.cacheop"] `application_vnduplanetcacheop
  | [@bs.as "application/vnd.uplanet.cacheop-wbxml"]
    `application_vnduplanetcacheopwbxml
  | [@bs.as "application/vnd.uplanet.channel"] `application_vnduplanetchannel
  | [@bs.as "application/vnd.uplanet.channel-wbxml"]
    `application_vnduplanetchannelwbxml
  | [@bs.as "application/vnd.uplanet.list"] `application_vnduplanetlist
  | [@bs.as "application/vnd.uplanet.listcmd"] `application_vnduplanetlistcmd
  | [@bs.as "application/vnd.uplanet.listcmd-wbxml"]
    `application_vnduplanetlistcmdwbxml
  | [@bs.as "application/vnd.uplanet.list-wbxml"]
    `application_vnduplanetlistwbxml
  | [@bs.as "application/vnd.uri-map"] `application_vndurimap
  | [@bs.as "application/vnd.uplanet.signal"] `application_vnduplanetsignal
  | [@bs.as "application/vnd.valve.source.material"]
    `application_vndvalvesourcematerial
  | [@bs.as "application/vnd.vcx"] `application_vndvcx
  | [@bs.as "application/vnd.vd-study"] `application_vndvdstudy
  | [@bs.as "application/vnd.vectorworks"] `application_vndvectorworks
  | [@bs.as "application/vnd.vel+json"] `application_vndveljson
  | [@bs.as "application/vnd.verimatrix.vcas"] `application_vndverimatrixvcas
  | [@bs.as "application/vnd.vidsoft.vidconference"]
    `application_vndvidsoftvidconference
  | [@bs.as "application/vnd.visio"] `application_vndvisio
  | [@bs.as "application/vnd.visionary"] `application_vndvisionary
  | [@bs.as "application/vnd.vividence.scriptfile"]
    `application_vndvividencescriptfile
  | [@bs.as "application/vnd.vsf"] `application_vndvsf
  | [@bs.as "application/vnd.wap.sic"] `application_vndwapsic
  | [@bs.as "application/vnd.wap-slc"] `application_vndwapslc
  | [@bs.as "application/vnd.wap-wbxml"] `application_vndwapwbxml
  | [@bs.as "application/vnd-wap-wmlc"] `application_vndwapwmlc
  | [@bs.as "application/vnd.wap.wmlscriptc"] `application_vndwapwmlscriptc
  | [@bs.as "application/vnd.webturbo"] `application_vndwebturbo
  | [@bs.as "application/vnd.wfa.p2p"] `application_vndwfap2p
  | [@bs.as "application/vnd.wfa.wsc"] `application_vndwfawsc
  | [@bs.as "application/vnd.windows.devicepairing"]
    `application_vndwindowsdevicepairing
  | [@bs.as "application/vnd.wmc"] `application_vndwmc
  | [@bs.as "application/vnd.wmf.bootstrap"] `application_vndwmfbootstrap
  | [@bs.as "application/vnd.wolfram.mathematica"]
    `application_vndwolframmathematica
  | [@bs.as "application/vnd.wolfram.mathematica.package"]
    `application_vndwolframmathematicapackage
  | [@bs.as "application/vnd.wolfram.player"] `application_vndwolframplayer
  | [@bs.as "application/vnd.wordperfect"] `application_vndwordperfect
  | [@bs.as "application/vnd.wqd"] `application_vndwqd
  | [@bs.as "application/vnd.wrq-hp3000-labelled"]
    `application_vndwrqhp3000labelled
  | [@bs.as "application/vnd.wt.stf"] `application_vndwtstf
  | [@bs.as "application/vnd.wv.csp+xml"] `application_vndwvcspxml
  | [@bs.as "application/vnd.wv.csp+wbxml"] `application_vndwvcspwbxml
  | [@bs.as "application/vnd.wv.ssp+xml"] `application_vndwvsspxml
  | [@bs.as "application/vnd.xacml+json"] `application_vndxacmljson
  | [@bs.as "application/vnd.xara"] `application_vndxara
  | [@bs.as "application/vnd.xfdl"] `application_vndxfdl
  | [@bs.as "application/vnd.xfdl.webform"] `application_vndxfdlwebform
  | [@bs.as "application/vnd.xmi+xml"] `application_vndxmixml
  | [@bs.as "application/vnd.xmpie.cpkg"] `application_vndxmpiecpkg
  | [@bs.as "application/vnd.xmpie.dpkg"] `application_vndxmpiedpkg
  | [@bs.as "application/vnd.xmpie.plan"] `application_vndxmpieplan
  | [@bs.as "application/vnd.xmpie.ppkg"] `application_vndxmpieppkg
  | [@bs.as "application/vnd.xmpie.xlim"] `application_vndxmpiexlim
  | [@bs.as "application/vnd.yamaha.hv-dic"] `application_vndyamahahvdic
  | [@bs.as "application/vnd.yamaha.hv-script"] `application_vndyamahahvscript
  | [@bs.as "application/vnd.yamaha.hv-voice"] `application_vndyamahahvvoice
  | [@bs.as "application/vnd.yamaha.openscoreformat.osfpvg+xml"]
    `application_vndyamahaopenscoreformatosfpvgxml
  | [@bs.as "application/vnd.yamaha.openscoreformat"]
    `application_vndyamahaopenscoreformat
  | [@bs.as "application/vnd.yamaha.remote-setup"]
    `application_vndyamaharemotesetup
  | [@bs.as "application/vnd.yamaha.smaf-audio"]
    `application_vndyamahasmafaudio
  | [@bs.as "application/vnd.yamaha.smaf-phrase"]
    `application_vndyamahasmafphrase
  | [@bs.as "application/vnd.yamaha.through-ngn"]
    `application_vndyamahathroughngn
  | [@bs.as "application/vnd.yamaha.tunnel-udpencap"]
    `application_vndyamahatunneludpencap
  | [@bs.as "application/vnd.yaoweme"] `application_vndyaoweme
  | [@bs.as "application/vnd.yellowriver-custom-menu"]
    `application_vndyellowrivercustommenu
  | [@bs.as "application/vnd.youtube.yt"] `application_vndyoutubeyt
  | [@bs.as "application/vnd.zul"] `application_vndzul
  | [@bs.as "application/vnd.zzazz.deck+xml"] `application_vndzzazzdeckxml
  | [@bs.as "application/voicexml+xml"] `application_voicexmlxml
  | [@bs.as "application/voucher-cms+json"] `application_vouchercmsjson
  | [@bs.as "application/vq-rtcpxr"] `application_vqrtcpxr
  | [@bs.as "application/watcherinfo+xml"] `application_watcherinfoxml
  | [@bs.as "application/webpush-options+json"] `application_webpushoptionsjson
  | [@bs.as "application/whoispp-query"] `application_whoisppquery
  | [@bs.as "application/whoispp-response"] `application_whoisppresponse
  | [@bs.as "application/widget"] `application_widget
  | [@bs.as "application/wita"] `application_wita
  | [@bs.as "application/wordperfect5.1"] `application_wordperfect51
  | [@bs.as "application/wsdl+xml"] `application_wsdlxml
  | [@bs.as "application/wspolicy+xml"] `application_wspolicyxml
  | [@bs.as "application/x-www-form-urlencoded"]
    `application_xwwwformurlencoded
  | [@bs.as "application/x400-bp"] `application_x400bp
  | [@bs.as "application/xacml+xml"] `application_xacmlxml
  | [@bs.as "application/xcap-att+xml"] `application_xcapattxml
  | [@bs.as "application/xcap-caps+xml"] `application_xcapcapsxml
  | [@bs.as "application/xcap-diff+xml"] `application_xcapdiffxml
  | [@bs.as "application/xcap-el+xml"] `application_xcapelxml
  | [@bs.as "application/xcap-error+xml"] `application_xcaperrorxml
  | [@bs.as "application/xcap-ns+xml"] `application_xcapnsxml
  | [@bs.as "application/xcon-conference-info-diff+xml"]
    `application_xconconferenceinfodiffxml
  | [@bs.as "application/xcon-conference-info+xml"]
    `application_xconconferenceinfoxml
  | [@bs.as "application/xenc+xml"] `application_xencxml
  | [@bs.as "application/xhtml+xml"] `application_xhtmlxml
  | [@bs.as "application/xliff+xml"] `application_xliffxml
  | [@bs.as "application/xml"] `application_xml
  | [@bs.as "application/xml-dtd"] `application_xmldtd
  | [@bs.as "application/xml-external-parsed-entity"]
    `application_xmlexternalparsedentity
  | [@bs.as "application/xml-patch+xml"] `application_xmlpatchxml
  | [@bs.as "application/xmpp+xml"] `application_xmppxml
  | [@bs.as "application/xop+xml"] `application_xopxml
  | [@bs.as "application/xv+xml"] `application_xvxml
  | [@bs.as "application/yang"] `application_yang
  | [@bs.as "application/yang-data+json"] `application_yangdatajson
  | [@bs.as "application/yang-data+xml"] `application_yangdataxml
  | [@bs.as "application/yang-patch+json"] `application_yangpatchjson
  | [@bs.as "application/yang-patch+xml"] `application_yangpatchxml
  | [@bs.as "application/yin+xml"] `application_yinxml
  | [@bs.as "application/zip"] `application_zip
  | [@bs.as "application/zlib"] `application_zlib
];