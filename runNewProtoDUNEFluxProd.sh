#!/bin/bash

OUTDIR=/exp/dune/data/users/chasnip/ProtoDUNESimulation/ProtoDUNEGSimpleNuFluxes_v2Apr2025
DATADIR=/exp/dune/data/users/chasnip/ProtoDUNESimulation/ProtoDUNENuFluxesTxtFiles_Oct2024
NOUTPUTS=10

for WOB in "np04" "133" "000" 
do
  file=${DATADIR}/*_w${WOB}_*.txt
  output_file="${OUTDIR}/gsimple_sps_pdhd_allflav_allhad_w${WOB}_total.root"

  ./GSimple_LArSoftConvert ${WOB} ${output_file} ${NOUTPUTS} ${file}
done
